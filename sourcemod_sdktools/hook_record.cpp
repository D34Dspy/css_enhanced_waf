#include "sourcehook.h"
#include "hooks.h"
#include "extension.h"
#include "basehandle.h"
#include "vector.h"
#include "utlvector.h"

#include "cbase.h"
#include "baseentity.h"
#include "../game/shared/usercmd.h"

// Moved to here because of CBaseEntity
#include "glue.hpp"

void CHookManager::PlayerRunCmdHook(int client, bool post)
{
	edict_t *pEdict = PEntityOfEntIndex(client);
	if (!pEdict)
	{
		return;
	}

	IServerUnknown *pUnknown = pEdict->GetUnknown();
	if (!pUnknown)
	{
		return;
	}

	CBaseEntity *pEntity = pUnknown->GetBaseEntity();
	if (!pEntity)
	{
		return;
	}

	std::vector<CHookRecord *> &runUserCmdHookVec = post ? m_runUserCmdPostHooks : m_runUserCmdHooks;
	for (size_t i = 0; i < runUserCmdHookVec.size(); ++i)
	{
		if (pEntity == runUserCmdHookVec[i]->pEntity)
		{
			return;
		}
	}


	CHookRecord* pRec = new CHookRecord;
	pRec->pParent = this;
	pRec->pEntity = pEntity;
	if (post)
		pRec->hookId = SMGlue_MkHook4_P2__PlayerRunCmdHook(SH_MEMBER(pRec, &CHookRecord::PlayerRunCmdPost), pEntity, true);
	else
		pRec->hookId = SMGlue_MkHook4_P2__PlayerRunCmdHook(SH_MEMBER(pRec, &CHookRecord::PlayerRunCmd), pEntity, false);
	runUserCmdHookVec.push_back(pRec);
}

void CHookRecord::PlayerRunCmd(CUserCmd *ucmd, IMoveHelper *moveHelper)
{
	if (!ucmd)
	{
		// RETURN_META(MRES_IGNORED);
		pEntity->GetSourcemodGlue()->l_SMGlue_P2__PlayerRunCmdHook2.create_return(MRES_IGNORED);
		return;
	}

	bool hasUsercmdsPreFwds = (pParent->m_usercmdsPreFwd->GetFunctionCount() > 0);
	bool hasUsercmdsFwds = (pParent->m_usercmdsFwd->GetFunctionCount() > 0);

	if (!hasUsercmdsPreFwds && !hasUsercmdsFwds)
	{
		// RETURN_META(MRES_IGNORED);
		pEntity->GetSourcemodGlue()->l_SMGlue_P2__PlayerRunCmdHook2.create_return(MRES_IGNORED);
		return;
	}

	CBaseEntity *pEntity = META_IFACEPTR(CBaseEntity);

	if (!pEntity)
	{
		// RETURN_META(MRES_IGNORED);
		pEntity->GetSourcemodGlue()->l_SMGlue_P2__PlayerRunCmdHook2.create_return(MRES_IGNORED);
		return;
	}

	edict_t *pEdict = gameents->BaseEntityToEdict(pEntity);

	if (!pEdict)
	{
		// RETURN_META(MRES_IGNORED);
		pEntity->GetSourcemodGlue()->l_SMGlue_P2__PlayerRunCmdHook2.create_return(MRES_IGNORED);
		return;
	}

	int client = IndexOfEdict(pEdict);


	cell_t result = 0;
	/* Impulse is a byte so we copy it back manually */
	cell_t impulse = ucmd->impulse;
	cell_t vel[3] = {sp_ftoc(ucmd->forwardmove), sp_ftoc(ucmd->sidemove), sp_ftoc(ucmd->upmove)};
	cell_t angles[3] = {sp_ftoc(ucmd->viewangles.x), sp_ftoc(ucmd->viewangles.y), sp_ftoc(ucmd->viewangles.z)};
	cell_t mouse[2] = {ucmd->mousedx, ucmd->mousedy};
	
	if (hasUsercmdsPreFwds)
	{
		pParent->m_usercmdsPreFwd->PushCell(client);
		pParent->m_usercmdsPreFwd->PushCell(ucmd->buttons);
		pParent->m_usercmdsPreFwd->PushCell(ucmd->impulse);
		pParent->m_usercmdsPreFwd->PushArray(vel, 3);
		pParent->m_usercmdsPreFwd->PushArray(angles, 3);
		pParent->m_usercmdsPreFwd->PushCell(ucmd->weaponselect);
		pParent->m_usercmdsPreFwd->PushCell(ucmd->weaponsubtype);
		pParent->m_usercmdsPreFwd->PushCell(ucmd->interpolated_amount_frac);
		pParent->m_usercmdsPreFwd->PushCell(ucmd->snapshot_tickcount);
		pParent->m_usercmdsPreFwd->PushArray(mouse, 2);
		pParent->m_usercmdsPreFwd->Execute();
	}

	if (hasUsercmdsFwds)
	{
		pParent->m_usercmdsFwd->PushCell(client);
		pParent->m_usercmdsFwd->PushCellByRef(&ucmd->buttons);
		pParent->m_usercmdsFwd->PushCellByRef(&impulse);
		pParent->m_usercmdsFwd->PushArray(vel, 3, SM_PARAM_COPYBACK);
		pParent->m_usercmdsFwd->PushArray(angles, 3, SM_PARAM_COPYBACK);
		pParent->m_usercmdsFwd->PushCellByRef(&ucmd->weaponselect);
		pParent->m_usercmdsFwd->PushCellByRef(&ucmd->weaponsubtype);
		pParent->m_usercmdsFwd->PushCellByRef((int*)&ucmd->interpolated_amount_frac);
		pParent->m_usercmdsFwd->PushCellByRef((int*)&ucmd->snapshot_tickcount);
		pParent->m_usercmdsFwd->PushCellByRef((int*)(&ucmd->snapshot_tickcount) + 1);
		pParent->m_usercmdsFwd->PushArray(mouse, 2, SM_PARAM_COPYBACK);
		pParent->m_usercmdsFwd->Execute(&result);

		ucmd->impulse = impulse;
		ucmd->forwardmove = sp_ctof(vel[0]);
		ucmd->sidemove = sp_ctof(vel[1]);
		ucmd->upmove = sp_ctof(vel[2]);
		ucmd->viewangles.x = sp_ctof(angles[0]);
		ucmd->viewangles.y = sp_ctof(angles[1]);
		ucmd->viewangles.z = sp_ctof(angles[2]);
		ucmd->mousedx = mouse[0];
		ucmd->mousedy = mouse[1];


		if (result == Pl_Handled)
		{
			// RETURN_META(MRES_SUPERCEDE);
			pEntity->GetSourcemodGlue()->l_SMGlue_P2__PlayerRunCmdHook2.create_return(MRES_SUPERCEDE);
			return;
		}
	}

	// RETURN_META(MRES_IGNORED);
	pEntity->GetSourcemodGlue()->l_SMGlue_P2__PlayerRunCmdHook2.create_return(MRES_IGNORED);
	return;
}

void CHookRecord::PlayerRunCmdPost(CUserCmd *ucmd, IMoveHelper *moveHelper)
{
	if (!ucmd)
	{
		// RETURN_META(MRES_IGNORED);
		pEntity->GetSourcemodGlue()->l_SMGlue_P2__PlayerRunCmdHook2.create_return(MRES_IGNORED);
		return;
	}

	if (pParent->m_usercmdsPostFwd->GetFunctionCount() == 0)
	{
		// RETURN_META(MRES_IGNORED);
		pEntity->GetSourcemodGlue()->l_SMGlue_P2__PlayerRunCmdHook2.create_return(MRES_IGNORED);
		return;
	}

	CBaseEntity *pEntity = META_IFACEPTR(CBaseEntity);

	if (!pEntity)
	{
		// RETURN_META(MRES_IGNORED);
		pEntity->GetSourcemodGlue()->l_SMGlue_P2__PlayerRunCmdHook2.create_return(MRES_IGNORED);
		return;
	}

	edict_t *pEdict = gameents->BaseEntityToEdict(pEntity);

	if (!pEdict)
	{
		// RETURN_META(MRES_IGNORED);
		pEntity->GetSourcemodGlue()->l_SMGlue_P2__PlayerRunCmdHook2.create_return(MRES_IGNORED);
		return;
	}

	int client = IndexOfEdict(pEdict);
	cell_t vel[3] = { sp_ftoc(ucmd->forwardmove), sp_ftoc(ucmd->sidemove), sp_ftoc(ucmd->upmove) };
	cell_t angles[3] = { sp_ftoc(ucmd->viewangles.x), sp_ftoc(ucmd->viewangles.y), sp_ftoc(ucmd->viewangles.z) };
	cell_t mouse[2] = { ucmd->mousedx, ucmd->mousedy };

	pParent->m_usercmdsPostFwd->PushCell(client);
	pParent->m_usercmdsPostFwd->PushCell(ucmd->buttons);
	pParent->m_usercmdsPostFwd->PushCell(ucmd->impulse);
	pParent->m_usercmdsPostFwd->PushArray(vel, 3);
	pParent->m_usercmdsPostFwd->PushArray(angles, 3);
	pParent->m_usercmdsPostFwd->PushCell(ucmd->weaponselect);
	pParent->m_usercmdsPostFwd->PushCell(ucmd->weaponsubtype);
	pParent->m_usercmdsPostFwd->PushCell((int)ucmd->snapshot_tickcount);
	pParent->m_usercmdsPostFwd->PushArray(mouse, 2);
	pParent->m_usercmdsPostFwd->Execute();

	// RETURN_META(MRES_IGNORED);
	pEntity->GetSourcemodGlue()->l_SMGlue_P2__PlayerRunCmdHook2.create_return(MRES_IGNORED);
	return;
}

void CHookRecord::ProcessPacket(struct netpacket_s *packet, bool bHasHeader)
{
	if (pParent->m_netFileReceiveFwd->GetFunctionCount() == 0)
	{
		// RETURN_META(MRES_IGNORED);
		pNetChannel->GetSourcemodGlue()->l_SMGlue_INetChannel__ProcessPacket.create_return(MRES_IGNORED);
		return;
	}

	pParent->m_pActiveNetChannel = pNetChannel;
	// RETURN_META(MRES_IGNORED);
	pNetChannel->GetSourcemodGlue()->l_SMGlue_INetChannel__ProcessPacket.create_return(MRES_IGNORED);
	return;
}

bool CHookRecord::FileExists(const char *filename, const char *pathID)
{
	if (pParent->m_pActiveNetChannel == NULL || pParent->m_netFileReceiveFwd->GetFunctionCount() == 0)
	{
		// RETURN_META_VALUE(MRES_IGNORED, false);
		basefilesystem->GetSourcemodGlue()->l_SMGlue_IBaseFileSystem__FileExists.create_return(MRES_IGNORED, {false});
		return false;
	}

	bool ret = SH_CALL(basefilesystem, &IBaseFileSystem::FileExists)(filename, pathID);
	if (ret == true) /* If the File Exists, the engine historically bails out. */
	{
		// RETURN_META_VALUE(MRES_IGNORED, false);
		basefilesystem->GetSourcemodGlue()->l_SMGlue_IBaseFileSystem__FileExists.create_return(MRES_IGNORED, {false});
		return false;
	}

	int userid = 0;
	IClient *pClient = (IClient *)pParent->m_pActiveNetChannel->GetMsgHandler();
	if (pClient != NULL)
	{
		userid = pClient->GetUserID();
	}

	cell_t res = Pl_Continue;
	pParent->m_netFileReceiveFwd->PushCell(playerhelpers->GetClientOfUserId(userid));
	pParent->m_netFileReceiveFwd->PushString(filename);
	pParent->m_netFileReceiveFwd->Execute(&res);

	if (res != Pl_Continue)
	{
		// RETURN_META_VALUE(MRES_SUPERCEDE, true);
		basefilesystem->GetSourcemodGlue()->l_SMGlue_IBaseFileSystem__FileExists.create_return(MRES_SUPERCEDE, {true});
		return true;
	}

	// RETURN_META_VALUE(MRES_IGNORED, false);
	basefilesystem->GetSourcemodGlue()->l_SMGlue_IBaseFileSystem__FileExists.create_return(MRES_IGNORED, {false});
	return false;
}

void CHookRecord::ProcessPacket_Post(struct netpacket_s* packet, bool bHasHeader)
{
	pParent->m_pActiveNetChannel = NULL;
	// RETURN_META(MRES_IGNORED);
	pNetChannel->GetSourcemodGlue()->l_SMGlue_INetChannel__ProcessPacket.create_return(MRES_IGNORED);
	return;
}

#if (SOURCE_ENGINE >= SE_ALIENSWARM || SOURCE_ENGINE == SE_LEFT4DEAD || SOURCE_ENGINE == SE_LEFT4DEAD2)
bool CHookRecord::SendFile(const char *filename, unsigned int transferID, bool isReplayDemo)
#else
bool CHookRecord::SendFile(const char *filename, unsigned int transferID)
#endif
{
	if (pParent->m_netFileSendFwd->GetFunctionCount() == 0)
	{
		// RETURN_META_VALUE(MRES_IGNORED, false);
		pNetChannel->GetSourcemodGlue()->l_SMGlue_INetChannel__SendFile.create_return(MRES_IGNORED, {false});
		return false;
	}

	if (pNetChannel == NULL)
	{
		// RETURN_META_VALUE(MRES_IGNORED, false);
		pNetChannel->GetSourcemodGlue()->l_SMGlue_INetChannel__SendFile.create_return(MRES_IGNORED, {false});
		return false;
	}

	int userid = 0;
	IClient *pClient = (IClient *)pNetChannel->GetMsgHandler();
	if (pClient != NULL)
	{
		userid = pClient->GetUserID();
	}

	cell_t res = Pl_Continue;
	pParent->m_netFileSendFwd->PushCell(playerhelpers->GetClientOfUserId(userid));
	pParent->m_netFileSendFwd->PushString(filename);
	pParent->m_netFileSendFwd->Execute(&res);

	if (res != Pl_Continue)
	{
		/* Mimic the Engine. */
#if (SOURCE_ENGINE >= SE_ALIENSWARM || SOURCE_ENGINE == SE_LEFT4DEAD || SOURCE_ENGINE == SE_LEFT4DEAD2)
		pNetChannel->DenyFile(filename, transferID, isReplayDemo);
#else
		pNetChannel->DenyFile(filename, transferID);
#endif
		// RETURN_META_VALUE(MRES_SUPERCEDE, false);
		pNetChannel->GetSourcemodGlue()->l_SMGlue_INetChannel__SendFile.create_return(MRES_SUPERCEDE, {false});
		return false;
	}

	// RETURN_META_VALUE(MRES_IGNORED, false);
	pNetChannel->GetSourcemodGlue()->l_SMGlue_INetChannel__SendFile.create_return(MRES_IGNORED, {false});
	return false;
}
