#include "IADTFactory.h"
#include "../sourcemod_core/sm_globals.h"
#include "bridge/include/CoreProvider.h"
#include "smsdk_ext.h"

class ISteamGameServer;

// SDKExtension* g_pExtensionIface = nullptr;

extern "C" ISteamGameServer* SteamGameServer() { return 0; }

// ITranslator *translator = nullptr;

// IForwardManager *g_pForwards;
// IHandleSys* g_pHandleSys;
// IADTFactory* adtfactory;

// ServerGlobals* gpGlobals = nullptr;

extern "C" void SteamAPI_RegisterCallback( class CCallbackBase *pCallback, int iCallback ) {}
extern "C" void SteamAPI_UnregisterCallback( class CCallbackBase *pCallback ) {}