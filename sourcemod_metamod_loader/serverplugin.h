/**
 * vim: set ts=4 :
 * ======================================================
 * Metamod:Source
 * Copyright (C) 2004-2008 AlliedModders LLC and authors.
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
 *
 * Version: $Id$
 */

#ifndef _INCLUDE_METAMOD_SOURCE_SERVERPLUGINS_H_
#define _INCLUDE_METAMOD_SOURCE_SERVERPLUGINS_H_

#include "loader_bridge.h"

#include "glue.hpp"

extern void *
mm_GetVspCallbacks(unsigned int version);


class CSourcemodGlueInterface;
class edict_t;

class ServerPlugin
{
	char game_name[128];
	unsigned int vsp_version;
	bool load_allowed;
	CSourcemodGlueInterface* m_pSourcemodGlue;
public:
	ServerPlugin();

	virtual CSourcemodGlueInterface* GetSourcemodGlue();

	virtual bool Load(QueryValveInterface engineFactory, QueryValveInterface gsFactory);
	virtual void Unload();
	virtual void Pause();
	virtual void UnPause();
	virtual const char *GetPluginDescription();
	virtual void LevelInit(char const *pMapName);
	virtual void ServerActivate(edict_t *pEdictList, int edictCount, int clientMax);
	virtual void GameFrame(bool simulating);
	virtual void LevelShutdown();
	virtual void ClientActive(edict_t *pEntity);
	virtual void ClientFullyConnect(edict_t *pEntity);
	virtual void ClientDisconnect(edict_t *pEntity);
	virtual void ClientPutInServer(edict_t *pEntity, char const *playername);
	virtual void SetCommandClient(int index);
	virtual void ClientSettingsChanged(edict_t *pEdict);
	virtual PLUGIN_RESULT ClientConnect(bool *bAllowConnect,
										edict_t *pEntity,
										const char *pszName,
										const char *pszAddress,
										char *reject,
										int maxrejectlen) ;
	virtual PLUGIN_RESULT ClientCommand(edict_t *pEntity);
	virtual PLUGIN_RESULT NetworkIDValidated(const char *pszUserName, const char *pszNetworkID);
	virtual void OnQueryCvarValueFinished(QueryCvarCookie_t iCookie,
										  edict_t *pPlayerEntity,
										  EQueryCvarValueStatus eStatus,
										  const char *pCvarName,
										  const char *pCvarValue);
	void PrepForLoad(unsigned int version);
};


extern IVspBridge *vsp_bridge;

#endif /* _INCLUDE_METAMOD_SOURCE_SERVERPLUGINS_H_ */

