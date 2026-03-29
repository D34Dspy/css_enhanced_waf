
#include "sys_sourcemod.h"
#include "dbg.h"
#include "dedicated.h"
#include "SourceBridge.h"
#include "ExtensionSys.h"
#include "interface.h"
#include "platform.h"
bool SM_OnLoad(CDedicatedAppSystemGroup*pAppSys){

    return true;
    Log("attempting to load metamod and sourcemod\n");
    // first load metamod source loader
	AppSystemInfo_t appSystems[] = 
	{
        { "sourcemodmetamodloader" DLL_EXT_STRING,				"ISERVERPLUGINCALLBACKS" },
		{ "", "" }	// Required to terminate the list
	};

	if ( !pAppSys->AddSystems( appSystems ) ) 
		return false;

    // load metamod source
    // since we have acquired plugin callbacks from the loader, 
    // we already have loaded the metamod core module at this point, 
    // so we can use the plugin manager, 
    // to load sourcemod
    // bool already;
    // char error[4096];

    // Log("Metamod_GetSmmPluginManager() %p\n", Metamod_GetSmmPluginManager());
    // auto pluginId = Metamod_GetSmmPluginManager()->Load("sourcemodcore", 0, already, error, 4096);
    // Log("Load() %d %s\n", pluginId, already ? "already" : "<>");

    // load sourcemod
    // load sourcemod extensions
    // Log("SourceMod_ExtensionManager() %p\n", SourceMod_ExtensionManager());

    return true;
}