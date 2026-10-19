//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $Workfile:     $
// $Date:         $
// $NoKeywords: $
//=============================================================================//
#include "cbase.h"
#include "entitylist.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

//=========================================================
// Multiplayer intermission spots.
//=========================================================
class CInfoIntermission:public CPointEntity
{
public:
	DECLARE_CLASS( CInfoIntermission, CPointEntity );

	void Spawn( void );
	void Think( void );
};

void CInfoIntermission::Spawn( void )
{
	SetSolid( SOLID_NONE );
	AddEffects( EF_NODRAW );
	SetLocalAngles( vec3_angle );
	SetNextThink( gpGlobals->curtime + 2 );// let targets spawn !
}

#if WAF_USE_SOURCEMOD == 1
#include <glue.hpp>
#endif
void CInfoIntermission::Think ( void )
{
#if WAF_USE_SOURCEMOD == 1
	auto sm_result = GetSourcemodGlue()->l_SMGlue_P0__Think.invoke_pre(this);
	if (GetSourcemodGlue()->l_SMGlue_P0__Think.skip_original())
	{
		sm_result = GetSourcemodGlue()->l_SMGlue_P0__Think.invoke_post(this, sm_result);
		return sm_result.unwrap();
	}
#endif
	CBaseEntity *pTarget;

	// find my target
	pTarget = gEntList.FindEntityByName( NULL, m_target.Get() );

	if ( pTarget )
	{
		Vector dir = pTarget->GetLocalOrigin() - GetLocalOrigin();
		VectorNormalize( dir );
		QAngle angles;
		VectorAngles( dir, angles );
		SetLocalAngles( angles );
	}
#if WAF_USE_SOURCEMOD == 1
	GetSourcemodGlue()->l_SMGlue_P0__Think.set_original_return_value({});
	sm_result = GetSourcemodGlue()->l_SMGlue_P0__Think.invoke_post(this, sm_result);
	if(GetSourcemodGlue()->l_SMGlue_P0__Think.overwrite_return())
		return sm_result.unwrap();
#endif
}

LINK_ENTITY_TO_CLASS( info_intermission, CInfoIntermission );
