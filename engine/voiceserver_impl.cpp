//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: This module implements the IVoiceServer interface.
//
// $NoKeywords: $
//=============================================================================//

#include "quakedef.h"
#include "server.h"
#include "ivoiceserver.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#if WAF_USE_SOURCEMOD == 1
#include "glue.hpp"
#endif

class CVoiceServer : public IVoiceServer
{
#if WAF_USE_SOURCEMOD == 1
	CSourcemodGlueInterface m_SourcemodGlue;
#endif
public:
#if WAF_USE_SOURCEMOD == 1
	virtual CSourcemodGlueInterface* GetSourcemodGlue() {
		return &m_SourcemodGlue;
	}
#endif
	
	virtual bool	GetClientListening(int iReceiver, int iSender)
	{
		// Make into client indices..
		--iReceiver;
		--iSender;

		if(iReceiver < 0 || iReceiver >= sv.GetClientCount() || iSender < 0 || iSender >= sv.GetClientCount() )
			return false;

		return sv.GetClient(iSender)->IsHearingClient( iReceiver );
	}
	
	virtual bool	SetClientListening(int iReceiver, int iSender, bool bListen)
	{
		// Make into client indices..
		--iReceiver;
		--iSender;
		
		if(iReceiver < 0 || iReceiver >= sv.GetClientCount() || iSender < 0 || iSender >= sv.GetClientCount() )
			return false;

		CGameClient *cl = sv.Client(iSender);
			
		cl->m_VoiceStreams.Set( iReceiver, bListen?1:0 );

		return true;
	}	
	virtual bool	SetClientProximity(int iReceiver, int iSender, bool bUseProximity)
	{
		// Make into client indices..
		--iReceiver;
		--iSender;

		if(iReceiver < 0 || iReceiver >= sv.GetClientCount() || iSender < 0 || iSender >= sv.GetClientCount() )
			return false;

		CGameClient *cl = sv.Client(iSender);

		cl->m_VoiceProximity.Set( iReceiver, bUseProximity );

		return true;
	}	
};


EXPOSE_SINGLE_INTERFACE(CVoiceServer, IVoiceServer, INTERFACEVERSION_VOICESERVER);
