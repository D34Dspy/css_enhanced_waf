/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod Counter-Strike:Source Extension
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

#include "extension.h"
#include "util_cstrike.h"
#include "RegNatives.h"
#include <iplayerinfo.h>
#include <sm_argbuffer.h>
#include "glue.hpp"

#if SOURCE_ENGINE == SE_CSGO
#include "itemdef-hash.h"

ClassnameMap g_mapClassToDefIdx;
ItemIndexMap g_mapDefIdxToClass;
WeaponIDMap g_mapWeaponIDToDefIdx;
#endif

#define REGISTER_ADDR(name, defaultret, code) \
	void *addr; \
	if (!g_pGameConf->GetMemSig(name, &addr) || !addr) \
	{ \
		g_pSM->LogError(myself, "Failed to lookup %s signature.", name); \
		return defaultret; \
	} \
	code; \
	g_RegNatives.Register(pWrapper);

#define GET_MEMSIG(name, defaultret) \
	if (!g_pGameConf->GetMemSig(name, &addr) || !addr) \
	{ \
		g_pSM->LogError(myself, "Failed to lookup %s signature.", name); \
		return defaultret;\
	}

#if SOURCE_ENGINE != SE_CSGO
void *GetWeaponInfo(int weaponID)
{
	return g_pGameDLL->GetSourcemodBridge()->GetWeaponInfo(weaponID);
}
#endif

const char *GetWeaponNameFromClassname(const char *weapon)
{
	char *szTemp = strstr((char *)weapon, "_");

	if (!szTemp)
	{
		return weapon;
	}
	else
	{
		return (const char *)((intptr_t)szTemp + 1);
	}
}

const char *GetTranslatedWeaponAlias(const char *weapon)
{
	return g_pGameDLL->GetSourcemodBridge()->GetTranslatedWeaponAlias(weapon);
}

int AliasToWeaponID(const char *weapon)
{
	return g_pGameDLL->GetSourcemodBridge()->AliasToWeaponID(weapon);
}

const char *WeaponIDToAlias(int weaponID)
{
	return g_pGameDLL->GetSourcemodBridge()->WeaponIDToAlias(weaponID);
}

bool IsValidWeaponID(int id)
{
	if (id <= (int)SMCSWeapon_NONE)
		return false;
#if SOURCE_ENGINE == SE_CSGO
	WeaponIDMap::Result res = g_mapWeaponIDToDefIdx.find((SMCSWeapon)id);
	if (!res.found())
		return false;
#else
	else if (id > SMCSWeapon_NIGHTVISION || !GetWeaponInfo(id))
		return false;
#endif
	return true;
}
