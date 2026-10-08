//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#ifndef ISERVERUNKNOWN_H
#define ISERVERUNKNOWN_H

#ifdef _WIN32
#pragma once
#endif


#include "ihandleentity.h"

class ICollideable;
class IServerNetworkable;
class CBaseEntity;
class CSourcemodGlueInterface;

// This is the server's version of IUnknown. We may want to use a QueryInterface-like
// mechanism if this gets big.
class IServerUnknown : public IHandleEntity
{
public:
	// Gets the interface to the collideable + networkable representation of the entity
	virtual ICollideable*		GetCollideable() = 0;
	virtual IServerNetworkable*	GetNetworkable() = 0;
	virtual CBaseEntity*		GetBaseEntity() = 0;
	virtual CSourcemodGlueInterface* GetSourcemodGlue() = 0; // Enforce Sourcemod Binding
};


#endif // ISERVERUNKNOWN_H
