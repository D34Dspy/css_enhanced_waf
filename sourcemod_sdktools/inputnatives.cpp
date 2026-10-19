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

#include "extension.h"
#include "variant-t.h"
#include <datamap.h>
#include <sm_argbuffer.h>

#include "glue.hpp"

#define ENTINDEX_TO_CBASEENTITY(ref, buffer) \
	buffer = gamehelpers->ReferenceToEntity(ref); \
	if (!buffer) \
	{ \
		return pContext->ThrowNativeError("Entity %d (%d) is not a CBaseEntity", gamehelpers->ReferenceToIndex(ref), ref); \
	}


static cell_t AcceptEntityInput(IPluginContext *pContext, const cell_t *params)
{
	CBaseEntity *pActivator, *pCaller, *pDest;

	char *inputname;
	ENTINDEX_TO_CBASEENTITY(params[1], pDest);
	pContext->LocalToString(params[2], &inputname);
	if (params[3] == -1)
	{
		pActivator = NULL;
	} else {
		ENTINDEX_TO_CBASEENTITY(params[3], pActivator);
	}
	if (params[4] == -1)
	{
		pCaller = NULL;
	} else {
		ENTINDEX_TO_CBASEENTITY(params[4], pCaller);
	}

	bool ret = g_pGameDLL->GetSourcemodBridge()->CBaseEntity__AcceptInput(pDest, inputname, pActivator, pCaller, g_Variant_t, params[5]);

	_init_variant_t();

	return (ret) ? 1 : 0;
}

sp_nativeinfo_t g_EntInputNatives[] =
{
	{"AcceptEntityInput",			AcceptEntityInput},
	{NULL,							NULL},
};
