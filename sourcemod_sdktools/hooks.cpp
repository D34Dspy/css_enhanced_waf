/**
* vim: set ts=4 :
* =============================================================================
* SourceMod SDKTools Extension
* Copyright (C) 2004-2008 AlliedModders LLC.  All rights reserved.
* =============================================================================
*
* This program is free software; you can redistribute it and/or modify it under
* the terms of the GNU General Public License, version 3.0, as published by the
* Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
* details.
*
* You should have received a copy of the GNU General Public License along with
* this program.  If not, see <http://www.gnu.org/licenses/>.
*
* As a special exception, AlliedModders LLC gives you permission to link the
* code of this program (as well as its derivative works) to "Half-Life 2," the
* "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
* by the Valve Corporation.  You must obey the GNU General Public License in
* all respects for all other code used.  Additionally, AlliedModders LLC grants
* this exception to all derivative works.  AlliedModders LLC defines further
* exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
* or <http://www.sourcemod.net/license.php>.
*
* Version: $Id$
*/

#include "sourcehook.h"
typedef int Activity;

#include "hooks.h"
#include "extension.h"

#include "basehandle.h"
#include "vector.h"
#include "utlvector.h"
#include <shareddefs.h>
#if SOURCE_ENGINE == SE_TF2 || SOURCE_ENGINE == SE_CSS || SOURCE_ENGINE == SE_DODS || SOURCE_ENGINE == SE_HL2DM
class CBasePlayer;
class CBaseEntityList;
#endif
// #define CLIENT_DLL
class CUserCmd
{
public:
	QAngle	viewangles;     
	float	forwardmove;   
	float	sidemove;      
	float	upmove;         
	int		buttons;		
	byte    impulse;        
	int		weaponselect;	
	int		weaponsubtype;
	short	mousedx;		
	short	mousedy;		
	bool	hasbeenpredicted;
	uint8 debug_hitboxes;
	float interpolated_amount_frac;
	uint64 snapshot_tickcount;

};
// #undef CLIENT_DLL
#include "filesystem.h"

#define FEATURECAP_PLAYERRUNCMD_11PARAMS	"SDKTools PlayerRunCmd 11Params"

CHookManager g_Hooks;
static bool PRCH_enabled = false;
static bool PRCH_used = false;
static bool PRCHPost_used = false;
static bool FILE_used = false;
#if !defined CLIENTVOICE_HOOK_SUPPORT
static bool PVD_used = false;
#endif

#include "glue.hpp"

SH_DECL_MANUALHOOK2_void(PlayerRunCmdHook, 0, 0, 0, CUserCmd *, IMoveHelper *);
SH_DECL_HOOK2(IBaseFileSystem, FileExists, SH_NOATTRIB, 0, bool, const char*, const char *);
#if (SOURCE_ENGINE >= SE_ALIENSWARM || SOURCE_ENGINE == SE_LEFT4DEAD || SOURCE_ENGINE == SE_LEFT4DEAD2)
SH_DECL_HOOK3(INetChannel, SendFile, SH_NOATTRIB, 0, bool, const char *, unsigned int, bool);
#else
SH_DECL_HOOK2(INetChannel, SendFile, SH_NOATTRIB, 0, bool, const char *, unsigned int);
#endif
#if !defined CLIENTVOICE_HOOK_SUPPORT
SH_DECL_HOOK1(IClientMessageHandler, ProcessVoiceData, SH_NOATTRIB, 0, bool, CLC_VoiceData *);
#endif
SH_DECL_HOOK2_void(INetChannel, ProcessPacket, SH_NOATTRIB, 0, struct netpacket_s *, bool);

SourceHook::CallClass<IBaseFileSystem> *basefilesystemPatch = NULL; 

CHookManager::CHookManager()
{
	m_usercmdsPreFwd = NULL;
	m_usercmdsFwd = NULL;
	m_usercmdsPostFwd = NULL;
	m_netFileSendFwd = NULL;
	m_netFileReceiveFwd = NULL;
	m_pActiveNetChannel = NULL;
}

void CHookManager::Initialize()
{
	int offset;
	if (g_pGameConf->GetOffset("PlayerRunCmd", &offset))
	{
		// SH_MANUALHOOK_RECONFIGURE(PlayerRunCmdHook, offset, 0, 0);
		PRCH_enabled = true;
	}
	else
	{
		g_pSM->LogError(myself, "Failed to find PlayerRunCmd offset - OnPlayerRunCmd forward disabled.");
		PRCH_enabled = false;
	}

	basefilesystemPatch = SH_GET_CALLCLASS(basefilesystem);

	m_netFileSendFwd = forwards->CreateForward("OnFileSend", ET_Event, 2, NULL, Param_Cell, Param_String);
	m_netFileReceiveFwd = forwards->CreateForward("OnFileReceive", ET_Event, 2, NULL, Param_Cell, Param_String);

	plsys->AddPluginsListener(this);
	sharesys->AddCapabilityProvider(myself, this, FEATURECAP_PLAYERRUNCMD_11PARAMS);
	
	m_usercmdsPreFwd = forwards->CreateForward("OnPlayerRunCmdPre", ET_Ignore, 11, NULL,
		Param_Cell,			// int client
		Param_Cell,			// int buttons
		Param_Cell,			// int impulse
		Param_Array,		// float vel[3]
		Param_Array,		// float angles[3]
		Param_Cell,			// int weapon
		Param_Cell,			// int subtype
		Param_Cell,			// int cmdnum
		Param_Cell,			// int tickcount
		Param_Cell,			// int seed
		Param_Array);		// int mouse[2]

	m_usercmdsFwd = forwards->CreateForward("OnPlayerRunCmd", ET_Event, 11, NULL,
		Param_Cell,			// client
		Param_CellByRef,	// buttons
		Param_CellByRef,	// impulse
		Param_Array,		// Float:vel[3]
		Param_Array,		// Float:angles[3]
		Param_CellByRef,	// weapon
		Param_CellByRef,	// subtype
		Param_CellByRef,	// cmdnum
		Param_CellByRef,	// tickcount
		Param_CellByRef,	// seed
		Param_Array);		// mouse[2]

	m_usercmdsPostFwd = forwards->CreateForward("OnPlayerRunCmdPost", ET_Ignore, 11, NULL,
		Param_Cell,			// client
		Param_Cell,			// buttons
		Param_Cell,			// impulse
		Param_Array,		// Float:vel[3]
		Param_Array,		// Float:angles[3]
		Param_Cell,			// weapon
		Param_Cell,			// subtype
		Param_Cell,			// cmdnum
		Param_Cell,			// tickcount
		Param_Cell,			// seed
		Param_Array);		// mouse[2]
}

void CHookManager::Shutdown()
{
	if (basefilesystemPatch)
	{
		SH_RELEASE_CALLCLASS(basefilesystemPatch);
		basefilesystemPatch = NULL;
	}

	if (PRCH_used)
	{
		for (size_t i = 0; i < m_runUserCmdHooks.size(); ++i)
		{
			delete m_runUserCmdHooks[i];
		}

		m_runUserCmdHooks.clear();
		PRCH_used = false;
	}

	if (PRCHPost_used)
	{
		for (size_t i = 0; i < m_runUserCmdPostHooks.size(); ++i)
		{
			delete m_runUserCmdPostHooks[i];
		}

		m_runUserCmdPostHooks.clear();
		PRCHPost_used = false;
	}

	if (FILE_used)
	{
		for (size_t i = 0; i < m_netChannelHooks.size(); ++i)
		{
			delete m_netChannelHooks[i];
		}

		m_netChannelHooks.clear();
		FILE_used = false;
	}
	
#if !defined CLIENTVOICE_HOOK_SUPPORT
	if (PVD_used)
	{
		for (size_t i = 0; i < m_netProcessVoiceData.size(); ++i)
		{
			delete m_netProcessVoiceData[i];
		}

		m_netProcessVoiceData.clear();
		PVD_used = false;
	}
#endif

	forwards->ReleaseForward(m_usercmdsPreFwd);
	forwards->ReleaseForward(m_usercmdsFwd);
	forwards->ReleaseForward(m_usercmdsPostFwd);
	forwards->ReleaseForward(m_netFileSendFwd);
	forwards->ReleaseForward(m_netFileReceiveFwd);

	plsys->RemovePluginsListener(this);
	sharesys->DropCapabilityProvider(myself, this, FEATURECAP_PLAYERRUNCMD_11PARAMS);
}

void CHookManager::OnMapStart()
{
	m_bFSTranHookWarned = false;
}

void CHookManager::OnClientConnect(int client)
{
	NetChannelHook(client);
}

#if !defined CLIENTVOICE_HOOK_SUPPORT
void CHookManager::OnClientConnected(int client)
{
	if (!PVD_used)
	{
		return;	
	}

	IClient *pClient = iserver->GetClient(client-1);
	if (!pClient)
	{
		return;
	}
	
	std::vector<CVTableHook *> &netProcessVoiceData = m_netProcessVoiceData;
	CVTableHook hook(pClient);
	for (size_t i = 0; i < netProcessVoiceData.size(); ++i)
	{
		if (hook == netProcessVoiceData[i])
		{
			return;
		}
	}
	
	auto msghandler = (IClientMessageHandler *)((intptr_t)(pClient) + sizeof(void *));
	int hookid = SH_ADD_VPHOOK(IClientMessageHandler, ProcessVoiceData, msghandler, SH_MEMBER(this, &CHookManager::ProcessVoiceData), true);
	hook.SetHookID(hookid);
	netProcessVoiceData.push_back(new CVTableHook(hook));
}
#endif

void CHookManager::OnClientPutInServer(int client)
{
	if (PRCH_used)
		PlayerRunCmdHook(client, false);
	if (PRCHPost_used)
		PlayerRunCmdHook(client, true);
}

void CHookManager::NetChannelHook(int client)
{
	if (!FILE_used)
		return;

	INetChannel *pNetChannel = static_cast<INetChannel *>(engine->GetPlayerNetInfo(client));
	if (pNetChannel == NULL)
	{
		return;
	}

	/* Normal NetChannel Hooks. */
	{
		CVTableHook nethook(pNetChannel);
		size_t iter;

		/* Initial Hook */
#if SOURCE_ENGINE == SE_TF2
		ConVarRef replay_enable("replay_enable", false);
		if (replay_enable.GetBool())
		{
			if (!m_bFSTranHookWarned)
			{
				g_pSM->LogError(myself, "OnFileSend hooks are not currently working on TF2 servers with Replay enabled.");
				m_bFSTranHookWarned = true;
			}
		}
		else
#endif
		if (!m_netChannelHooks.size())
		{
			CHookRecord* pHk2 = new CHookRecord;
			pHk2->pParent = this;
			pHk2->pNetChannel = pNetChannel;
			pHk2->hookId = SH_ADD_VPHOOK(IBaseFileSystem, FileExists, basefilesystem, SH_MEMBER(pHk2, &CHookRecord::FileExists), false);
			m_netChannelHooks.push_back(pHk2);
		}

		for (iter = 0; iter < m_netChannelHooks.size(); ++iter)
		{
			if (pNetChannel == m_netChannelHooks[iter]->pNetChannel)
			{
				break;
			}
		}

		if (iter == m_netChannelHooks.size())
		{
			CHookRecord* pHk = new CHookRecord;
			pHk->pParent = this;
			pHk->pNetChannel = pNetChannel;
			pHk->hookId = SH_ADD_VPHOOK(INetChannel, SendFile, pNetChannel, SH_MEMBER(pHk, &CHookRecord::SendFile), false);
			m_netChannelHooks.push_back(pHk);

			pHk = new CHookRecord;
			pHk->pParent = this;
			pHk->pNetChannel = pNetChannel;
			pHk->hookId = SH_ADD_VPHOOK(INetChannel, ProcessPacket, pNetChannel, SH_MEMBER(pHk, &CHookRecord::ProcessPacket), false);
			m_netChannelHooks.push_back(pHk);
			
			pHk = new CHookRecord;
			pHk->pParent = this;
			pHk->pNetChannel = pNetChannel;
			pHk->hookId = SH_ADD_VPHOOK(INetChannel, ProcessPacket, pNetChannel, SH_MEMBER(pHk, &CHookRecord::ProcessPacket_Post), true);
			m_netChannelHooks.push_back(pHk);
		}
	}
}

#if !defined CLIENTVOICE_HOOK_SUPPORT
bool CHookManager::ProcessVoiceData(CLC_VoiceData *msg)
{
	IClient *pClient = (IClient *)((intptr_t)(META_IFACEPTR(IClient)) - sizeof(void *));
	if (pClient == NULL)
	{
		return true;
	}

	int client = pClient->GetPlayerSlot() + 1;

	if (g_hTimerSpeaking[client])
	{
		timersys->KillTimer(g_hTimerSpeaking[client]);
	}

	g_hTimerSpeaking[client] = timersys->CreateTimer(&g_SdkTools, 0.3f, (void *)(intptr_t)client, 0);

	m_OnClientSpeaking->PushCell(client);
	m_OnClientSpeaking->Execute();

	return true;
}
#endif

void CHookManager::OnPluginLoaded(IPlugin *plugin)
{
	if (PRCH_enabled)
	{
		bool changed = false;
		if (!PRCH_used && ((m_usercmdsFwd->GetFunctionCount() > 0) || (m_usercmdsPreFwd->GetFunctionCount() > 0)))
		{
			PRCH_used = true;
			changed = true;
		}
		if (!PRCHPost_used && (m_usercmdsPostFwd->GetFunctionCount() > 0))
		{
			PRCHPost_used = true;
			changed = true;
		}

		// Only check the hooks on the players if a new hook is used by this plugin.
		if (changed)
		{
			int MaxClients = playerhelpers->GetMaxClients();
			for (int i = 1; i <= MaxClients; i++)
			{
				if (playerhelpers->GetGamePlayer(i)->IsInGame())
				{
					OnClientPutInServer(i);
				}
			}
		}
	}

	if (!FILE_used && (m_netFileSendFwd->GetFunctionCount() || m_netFileReceiveFwd->GetFunctionCount()))
	{
		FILE_used = true;

		int MaxClients = playerhelpers->GetMaxClients();
		for (int i = 1; i <= MaxClients; i++)
		{
			if (playerhelpers->GetGamePlayer(i)->IsConnected())
			{
				OnClientConnect(i);
			}
		}
	}
	
#if !defined CLIENTVOICE_HOOK_SUPPORT
	if (!PVD_used && (m_OnClientSpeaking->GetFunctionCount() || m_OnClientSpeakingEnd->GetFunctionCount()))
	{
		PVD_used = true;

		int MaxClients = playerhelpers->GetMaxClients();
		for (int i = 1; i <= MaxClients; i++)
		{
			if (playerhelpers->GetGamePlayer(i)->IsConnected())
			{
				OnClientConnected(i);
			}
		}
	}
#endif
}

void CHookManager::OnPluginUnloaded(IPlugin *plugin)
{
	if (PRCH_used && (!m_usercmdsFwd->GetFunctionCount() && !m_usercmdsPreFwd->GetFunctionCount()))
	{
		for (size_t i = 0; i < m_runUserCmdHooks.size(); ++i)
		{
			delete m_runUserCmdHooks[i];
		}

		m_runUserCmdHooks.clear();
		PRCH_used = false;
	}

	if (PRCHPost_used && !m_usercmdsPostFwd->GetFunctionCount())
	{
		for (size_t i = 0; i < m_runUserCmdPostHooks.size(); ++i)
		{
			delete m_runUserCmdPostHooks[i];
		}

		m_runUserCmdPostHooks.clear();
		PRCHPost_used = false;
	}

	if (FILE_used && !m_netFileSendFwd->GetFunctionCount() && !m_netFileReceiveFwd->GetFunctionCount())
	{
		for (size_t i = 0; i < m_netChannelHooks.size(); ++i)
		{
			delete m_netChannelHooks[i];
		}

		m_netChannelHooks.clear();
		FILE_used = false;
	}
	
#if !defined CLIENTVOICE_HOOK_SUPPORT
	if (PVD_used && !m_OnClientSpeaking->GetFunctionCount() && !m_OnClientSpeakingEnd->GetFunctionCount())
	{
		for (size_t i = 0; i < m_netProcessVoiceData.size(); ++i)
		{
			delete m_netProcessVoiceData[i];
		}

		m_netProcessVoiceData.clear();
		PVD_used = false;
	}
#endif
}

FeatureStatus CHookManager::GetFeatureStatus(FeatureType type, const char *name)
{
	return FeatureStatus_Available;
}
