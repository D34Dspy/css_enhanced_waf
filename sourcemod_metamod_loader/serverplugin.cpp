/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Metamod:Source
 * Copyright (C) 2004-2009 AlliedModders LLC and authors.
 * All rights reserved.
 * ======================================================
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software in a
 * product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include "loader.h"
#include <sh_memfuncinfo.h>
#include <sh_memory.h>
#include "serverplugin.h"
#include "gamedll.h"

class CCommand;
class IServerPluginCallbacks;
struct edict_t;

class IRandomThings
{
  public:
	virtual PLUGIN_RESULT ClientCommand( edict_t* pEntity, const CCommand& args )
	{
		return PLUGIN_CONTINUE;
	}
};

IVspBridge* vsp_bridge = NULL;

class CSourcemodGlueInterface;

/**
 * The vtable must match the general layout for ISPC.  We modify the vtable
 * based on what we get back.
 */
CSourcemodGlueInterface* ServerPlugin::GetSourcemodGlue()
{
	return m_pSourcemodGlue;
}

bool ServerPlugin::Load( QueryValveInterface engineFactory, QueryValveInterface gsFactory )
{
	if ( !load_allowed )
	{
		return false;
	}

	load_allowed = false;

	/* Backend should already filled in if loaded as gamedll */
	if ( gamedll_bridge == NULL )
	{
		mm_GetGameName( game_name, sizeof( game_name ) );

		mm_backend = mm_DetermineBackend( engineFactory, gsFactory, game_name );
	}

	if ( mm_backend == MMBackend_UNKNOWN )
	{
		mm_LogFatal( "Could not detect engine version" );
		return false;
	}

	void** this_vtable;
	this_vtable = ( void** )*( void** )this;

	if ( mm_backend != MMBackend_Episode1 && mm_backend != MMBackend_DarkMessiah )
	{
		/* We need to insert the right type of call into this vtable */
		void** vtable_src;
		IRandomThings sample;
		SourceHook::MemFuncInfo mfp_dest, mfp_src;

		mfp_dest.isVirtual = false;
		mfp_src.isVirtual  = false;

		SourceHook::GetFuncInfo( &ServerPlugin::ClientCommand, mfp_dest );
		SourceHook::GetFuncInfo( &IRandomThings::ClientCommand, mfp_src );

		assert( mfp_dest.isVirtual );
		assert( mfp_dest.thisptroffs == 0 );
		assert( mfp_dest.vtbloffs == 0 );
		assert( mfp_src.isVirtual );
		assert( mfp_src.thisptroffs == 0 );
		assert( mfp_src.vtbloffs == 0 );

		vtable_src = ( void** )*( void** )&sample;
		SourceHook::SetMemAccess( &this_vtable[mfp_dest.vtblindex],
								  sizeof( void* ),
								  SH_MEM_READ | SH_MEM_WRITE | SH_MEM_EXEC );
		this_vtable[mfp_dest.vtblindex] = vtable_src[mfp_src.vtblindex];
	}

	/* AS inserted ClientFullyConnect into vtable, so move entries up on older engines */
	if ( mm_backend != MMBackend_AlienSwarm && mm_backend != MMBackend_Portal2 && mm_backend != MMBackend_Blade
		 && mm_backend != MMBackend_Insurgency && mm_backend != MMBackend_DOI && mm_backend != MMBackend_CSGO
		 && mm_backend != MMBackend_DOTA )
	{
		SourceHook::MemFuncInfo mfp_fconnect;
		mfp_fconnect.isVirtual = false;

		SourceHook::GetFuncInfo( &ServerPlugin::ClientFullyConnect, mfp_fconnect );

		assert( mfp_fconnect.isVirtual );
		assert( mfp_fconnect.thisptroffs == 0 );
		assert( mfp_fconnect.vtbloffs == 0 );

		/* Shifting ClientDisconnect through OnQueryCvarValueFinished up into slot for
		 * ClientFullyConnect (8 entries)
		 */
		SourceHook::SetMemAccess( &this_vtable[mfp_fconnect.vtblindex],
								  sizeof( void* ) * 8,
								  SH_MEM_READ | SH_MEM_WRITE | SH_MEM_EXEC );
		memmove( &this_vtable[mfp_fconnect.vtblindex], &this_vtable[mfp_fconnect.vtblindex + 1], sizeof( void* ) * 8 );
	}

	char error[255];
	if ( gamedll_bridge == NULL )
	{
		if ( !mm_LoadMetamodLibrary( mm_backend, error, sizeof( error ) ) )
		{
			mm_LogFatal( "Detected engine %d but could not load: %s", mm_backend, error );
			return false;
		}
	}

	typedef IVspBridge* ( *GetVspBridge )();
	GetVspBridge get_bridge = ( GetVspBridge )mm_GetProcAddress( "GetVspBridge" );
	if ( get_bridge == NULL )
	{
		if ( gamedll_bridge == NULL )
		{
			mm_UnloadMetamodLibrary();
		}
		mm_LogFatal( "Detected engine %d but could not find GetVspBridge callback", mm_backend );
		return false;
	}

	vsp_bridge = get_bridge();

	vsp_bridge_info info;

	info.engineFactory = engineFactory;
	info.gsFactory	   = gsFactory;
	info.vsp_callbacks = ( IServerPluginCallbacks* )this;
	info.vsp_version   = vsp_version;

	strcpy( error, "Unknown error" );
	if ( !vsp_bridge->Load( &info, error, sizeof( error ) ) )
	{
		vsp_bridge = NULL;
		if ( gamedll_bridge == NULL )
		{
			mm_UnloadMetamodLibrary();
		}
		mm_LogFatal( "Unknown error loading Metamod for engine %d: %s", mm_backend, error );
		return false;
	}

	return true;
}

void ServerPlugin::Unload()
{
	if ( vsp_bridge == NULL )
	{
		return;
	}
	vsp_bridge->Unload();

	if ( gamedll_bridge == NULL )
	{
		mm_UnloadMetamodLibrary();
	}
}

void ServerPlugin::Pause()
{
}

void ServerPlugin::UnPause()
{
}

const char* ServerPlugin::GetPluginDescription()
{
	if ( vsp_bridge == NULL )
	{
		return "Metamod:Source Loader Shim";
	}
	return vsp_bridge->GetDescription();
}

void ServerPlugin::LevelInit( const char* pMapName )
{
}

void ServerPlugin::ServerActivate( edict_t* pEdictList, int edictCount, int clientMax )
{
}

void ServerPlugin::GameFrame( bool simulating )
{
}

void ServerPlugin::LevelShutdown()
{
}

void ServerPlugin::ClientActive( edict_t* pEntity )
{
}

void ServerPlugin::ClientFullyConnect( edict_t* pEntity )
{
}

void ServerPlugin::ClientDisconnect( edict_t* pEntity )
{
}

void ServerPlugin::ClientPutInServer( edict_t* pEntity, const char* playername )
{
}

void ServerPlugin::SetCommandClient( int index )
{
}

void ServerPlugin::ClientSettingsChanged( edict_t* pEdict )
{
}

PLUGIN_RESULT ServerPlugin::ClientConnect( bool* bAllowConnect,
										   edict_t* pEntity,
										   const char* pszName,
										   const char* pszAddress,
										   char* reject,
										   int maxrejectlen )
{
	return PLUGIN_CONTINUE;
}

PLUGIN_RESULT ServerPlugin::ClientCommand( edict_t* pEntity )
{
	return PLUGIN_CONTINUE;
}

PLUGIN_RESULT ServerPlugin::NetworkIDValidated( const char* pszUserName, const char* pszNetworkID )
{
	return PLUGIN_CONTINUE;
}

void ServerPlugin::OnQueryCvarValueFinished( QueryCvarCookie_t iCookie,
											 edict_t* pPlayerEntity,
											 EQueryCvarValueStatus eStatus,
											 const char* pCvarName,
											 const char* pCvarValue )
{
}

void ServerPlugin::PrepForLoad( unsigned int version )
{
	vsp_version	 = version;
	load_allowed = true;
}

ServerPlugin mm_vsp_callbacks;

void* mm_GetVspCallbacks( unsigned int version )
{
	if ( vsp_bridge != NULL )
	{
		return NULL;
	}

	/* Only support versions 1 or 2 right now */
	if ( version > 2 )
	{
		return NULL;
	}

	mm_vsp_callbacks.PrepForLoad( version );

	return &mm_vsp_callbacks;
}
