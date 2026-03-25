#pragma once

#include "tier1/convar.h"
#include "filesystem.h"
#include "protocol.h"
#ifndef GLUE_HPP
#define GLUE_HPP

#include "../sourcemod_metamod_core/sourcehook/FastDelegate.h"

#define PLAYERLOCALDATA_H
#define NO_ENTITY_PREDICTION
#define CBASEPLAYER_HIDE_INLINE
#include "router.hpp"
#include "igameevents.h"
#include "iserverplugin.h"
#include "ivoiceserver.h"
#include "eiface.h"
#include "engine/IEngineSound.h"
#include "game/shared/ehandle.h"
class CBaseEntity;
#include "game/shared/shareddefs.h"

class CTakeDamageInfo;
class CBaseCombatWeapon;
class CDmgAccumulator;
class IPhysicsObject;
class CUserCmd;
class INetChannel;
class CLC_VoiceData;
class CPredictableId;
class IEntityListener;
class IEntityListener2;
class IClientMessageHandler;

#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef GLUE_LOCAL
    #define GLUE_API __declspec(dllexport)
  #else
    #define GLUE_API __declspec(dllimport)
  #endif
#else
  #if __GNUC__ >= 4
    #define GLUE_API __attribute__((visibility("default")))
  #else
    #define GLUE_API
  #endif
#endif

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<ConCommandBase *>, ICvar> g_SMGlue_ICvar__UnregisterConCommand;
inline int SMGlue_MkHook4_ICvar__UnregisterConCommand ( fastdelegate::FastDelegate1<ConCommandBase *> delegate , ICvar * instance, bool post = false ) {return g_SMGlue_ICvar__UnregisterConCommand.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_ICvar__UnregisterConCommand ( int hk, ICvar * instance, bool post = false ) {g_SMGlue_ICvar__UnregisterConCommand.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<ConCommandBase *, bool>, ICvar> g_SMGlue_ICvar__RegisterConCommand;
inline int SMGlue_MkHook4_ICvar__RegisterConCommand ( fastdelegate::FastDelegate2<ConCommandBase *, bool> delegate , ICvar * instance, bool post = false ) {return g_SMGlue_ICvar__RegisterConCommand.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_ICvar__RegisterConCommand ( int hk, ICvar * instance, bool post = false ) {g_SMGlue_ICvar__RegisterConCommand.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<IGameEvent *, bool, bool>, IGameEventManager2> g_SMGlue_IGameEventManager2__FireEvent;
inline int SMGlue_MkHook4_IGameEventManager2__FireEvent ( fastdelegate::FastDelegate2<IGameEvent *, bool, bool> delegate , IGameEventManager2 * instance, bool post = false ) {return g_SMGlue_IGameEventManager2__FireEvent.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IGameEventManager2__FireEvent ( int hk, IGameEventManager2 * instance, bool post = false ) {g_SMGlue_IGameEventManager2__FireEvent.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate3<ConVar *, const char *, float>, ICvar> g_SMGlue_ICvar__CallGlobalChangeCallbacks;
inline int SMGlue_MkHook4_ICvar__CallGlobalChangeCallbacks ( fastdelegate::FastDelegate3<ConVar *, const char *, float> delegate , ICvar * instance, bool post = false ) {return g_SMGlue_ICvar__CallGlobalChangeCallbacks.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_ICvar__CallGlobalChangeCallbacks ( int hk, ICvar * instance, bool post = false ) {g_SMGlue_ICvar__CallGlobalChangeCallbacks.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<ConVar *, const char *>, ICvar> g_SMGlue_ICvar__CallGlobalChangeCallback;
inline int SMGlue_MkHook4_ICvar__CallGlobalChangeCallback ( fastdelegate::FastDelegate2<ConVar *, const char *> delegate , ICvar * instance, bool post = false ) {return g_SMGlue_ICvar__CallGlobalChangeCallback.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_ICvar__CallGlobalChangeCallback ( int hk, ICvar * instance, bool post = false ) {g_SMGlue_ICvar__CallGlobalChangeCallback.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate5<QueryCvarCookie_t, edict_t *, EQueryCvarValueStatus, const char *, const char *>, IServerGameDLL> g_SMGlue_IServerGameDLL__OnQueryCvarValueFinished;
inline int SMGlue_MkHook4_IServerGameDLL__OnQueryCvarValueFinished ( fastdelegate::FastDelegate5<QueryCvarCookie_t, edict_t *, EQueryCvarValueStatus, const char *, const char *> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_IServerGameDLL__OnQueryCvarValueFinished.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameDLL__OnQueryCvarValueFinished ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_IServerGameDLL__OnQueryCvarValueFinished.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate5<QueryCvarCookie_t, edict_t *, EQueryCvarValueStatus, const char *, const char *>, IServerPluginCallbacks> g_SMGlue_IServerPluginCallbacks__OnQueryCvarValueFinished;
inline int SMGlue_MkHook4_IServerPluginCallbacks__OnQueryCvarValueFinished ( fastdelegate::FastDelegate5<QueryCvarCookie_t, edict_t *, EQueryCvarValueStatus, const char *, const char *> delegate , IServerPluginCallbacks * instance, bool post = false ) {return g_SMGlue_IServerPluginCallbacks__OnQueryCvarValueFinished.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerPluginCallbacks__OnQueryCvarValueFinished ( int hk, IServerPluginCallbacks * instance, bool post = false ) {g_SMGlue_IServerPluginCallbacks__OnQueryCvarValueFinished.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<const CCommand &>, ConCommand> g_SMGlue_ConCommand__Dispatch;
inline int SMGlue_MkHook4_ConCommand__Dispatch ( fastdelegate::FastDelegate1<const CCommand &> delegate , ConCommand * instance, bool post = false ) {return g_SMGlue_ConCommand__Dispatch.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_ConCommand__Dispatch ( int hk, ConCommand * instance, bool post = false ) {g_SMGlue_ConCommand__Dispatch.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<int>, IServerGameClients> g_SMGlue_IServerGameClients__SetCommandClient;
inline int SMGlue_MkHook4_IServerGameClients__SetCommandClient ( fastdelegate::FastDelegate1<int> delegate , IServerGameClients * instance, bool post = false ) {return g_SMGlue_IServerGameClients__SetCommandClient.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameClients__SetCommandClient ( int hk, IServerGameClients * instance, bool post = false ) {g_SMGlue_IServerGameClients__SetCommandClient.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<const char *>, IVEngineServer> g_SMGlue_IVEngineServer__LogPrint;
inline int SMGlue_MkHook4_IVEngineServer__LogPrint ( fastdelegate::FastDelegate1<const char *> delegate , IVEngineServer * instance, bool post = false ) {return g_SMGlue_IVEngineServer__LogPrint.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IVEngineServer__LogPrint ( int hk, IVEngineServer * instance, bool post = false ) {g_SMGlue_IVEngineServer__LogPrint.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate4<edict_t *, DIALOG_TYPE, KeyValues *, IServerPluginCallbacks *>, IServerPluginHelpers> g_SMGlue_IServerPluginHelpers__CreateMessage;
inline int SMGlue_MkHook4_IServerPluginHelpers__CreateMessage ( fastdelegate::FastDelegate4<edict_t *, DIALOG_TYPE, KeyValues *, IServerPluginCallbacks *> delegate , IServerPluginHelpers * instance, bool post = false ) {return g_SMGlue_IServerPluginHelpers__CreateMessage.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerPluginHelpers__CreateMessage ( int hk, IServerPluginHelpers * instance, bool post = false ) {g_SMGlue_IServerPluginHelpers__CreateMessage.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<const char *, const char *>, IVEngineServer> g_SMGlue_IVEngineServer__ChangeLevel;
inline int SMGlue_MkHook4_IVEngineServer__ChangeLevel ( fastdelegate::FastDelegate2<const char *, const char *> delegate , IVEngineServer * instance, bool post = false ) {return g_SMGlue_IVEngineServer__ChangeLevel.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IVEngineServer__ChangeLevel ( int hk, IVEngineServer * instance, bool post = false ) {g_SMGlue_IVEngineServer__ChangeLevel.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate5<edict_t *, const char *, const char *, char *, int, bool>, IServerGameClients> g_SMGlue_IServerGameClients__ClientConnect;
inline int SMGlue_MkHook4_IServerGameClients__ClientConnect ( fastdelegate::FastDelegate5<edict_t *, const char *, const char *, char *, int, bool> delegate , IServerGameClients * instance, bool post = false ) {return g_SMGlue_IServerGameClients__ClientConnect.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameClients__ClientConnect ( int hk, IServerGameClients * instance, bool post = false ) {g_SMGlue_IServerGameClients__ClientConnect.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<edict_t *, const char *>, IServerGameClients> g_SMGlue_IServerGameClients__ClientPutInServer;
inline int SMGlue_MkHook4_IServerGameClients__ClientPutInServer ( fastdelegate::FastDelegate2<edict_t *, const char *> delegate , IServerGameClients * instance, bool post = false ) {return g_SMGlue_IServerGameClients__ClientPutInServer.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameClients__ClientPutInServer ( int hk, IServerGameClients * instance, bool post = false ) {g_SMGlue_IServerGameClients__ClientPutInServer.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<edict_t *>, IServerGameClients> g_SMGlue_IServerGameClients__ClientDisconnect;
inline int SMGlue_MkHook4_IServerGameClients__ClientDisconnect ( fastdelegate::FastDelegate1<edict_t *> delegate , IServerGameClients * instance, bool post = false ) {return g_SMGlue_IServerGameClients__ClientDisconnect.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameClients__ClientDisconnect ( int hk, IServerGameClients * instance, bool post = false ) {g_SMGlue_IServerGameClients__ClientDisconnect.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<edict_t *, const CCommand &>, IServerGameClients> g_SMGlue_IServerGameClients__ClientCommand;
inline int SMGlue_MkHook4_IServerGameClients__ClientCommand ( fastdelegate::FastDelegate2<edict_t *, const CCommand &> delegate , IServerGameClients * instance, bool post = false ) {return g_SMGlue_IServerGameClients__ClientCommand.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameClients__ClientCommand ( int hk, IServerGameClients * instance, bool post = false ) {g_SMGlue_IServerGameClients__ClientCommand.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<edict_t *, const char*>, IVEngineServer> g_SMGlue_IVEngineServer__ClientCommand;

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<edict_t *>, IServerGameClients> g_SMGlue_IServerGameClients__ClientSettingsChanged;
inline int SMGlue_MkHook4_IServerGameClients__ClientSettingsChanged ( fastdelegate::FastDelegate1<edict_t *> delegate , IServerGameClients * instance, bool post = false ) {return g_SMGlue_IServerGameClients__ClientSettingsChanged.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameClients__ClientSettingsChanged ( int hk, IServerGameClients * instance, bool post = false ) {g_SMGlue_IServerGameClients__ClientSettingsChanged.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<edict_t *, KeyValues *>, IServerGameClients> g_SMGlue_IServerGameClients__ClientCommandKeyValues;
inline int SMGlue_MkHook4_IServerGameClients__ClientCommandKeyValues ( fastdelegate::FastDelegate2<edict_t *, KeyValues *> delegate , IServerGameClients * instance, bool post = false ) {return g_SMGlue_IServerGameClients__ClientCommandKeyValues.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameClients__ClientCommandKeyValues ( int hk, IServerGameClients * instance, bool post = false ) {g_SMGlue_IServerGameClients__ClientCommandKeyValues.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate3<edict_t *, int, int>, IServerGameDLL> g_SMGlue_IServerGameDLL__ServerActivate;
inline int SMGlue_MkHook4_IServerGameDLL__ServerActivate ( fastdelegate::FastDelegate3<edict_t *, int, int> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_IServerGameDLL__ServerActivate.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameDLL__ServerActivate ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_IServerGameDLL__ServerActivate.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<bool>, IServerGameDLL> g_SMGlue_IServerGameDLL__ServerHibernationUpdate;
inline int SMGlue_MkHook4_IServerGameDLL__ServerHibernationUpdate ( fastdelegate::FastDelegate1<bool> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_IServerGameDLL__ServerHibernationUpdate.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameDLL__ServerHibernationUpdate ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_IServerGameDLL__ServerHibernationUpdate.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<bool>, IServerGameDLL> g_SMGlue_IServerGameDLL__SetServerHibernation;
inline int SMGlue_MkHook4_IServerGameDLL__SetServerHibernation ( fastdelegate::FastDelegate1<bool> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_IServerGameDLL__SetServerHibernation.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameDLL__SetServerHibernation ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_IServerGameDLL__SetServerHibernation.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<edict_t *, const char *>, IVEngineServer> g_SMGlue_IVEngineServer__ClientPrintf;
inline int SMGlue_MkHook4_IVEngineServer__ClientPrintf ( fastdelegate::FastDelegate2<edict_t *, const char *> delegate , IVEngineServer * instance, bool post = false ) {return g_SMGlue_IVEngineServer__ClientPrintf.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IVEngineServer__ClientPrintf ( int hk, IVEngineServer * instance, bool post = false ) {g_SMGlue_IVEngineServer__ClientPrintf.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate6<const char *, const char *, const char *, const char *, bool, bool, bool>, IServerGameDLL> g_SMGlue_IServerGameDLL__LevelInit;
inline int SMGlue_MkHook4_IServerGameDLL__LevelInit ( fastdelegate::FastDelegate6<const char *, const char *, const char *, const char *, bool, bool, bool> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_IServerGameDLL__LevelInit.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameDLL__LevelInit ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_IServerGameDLL__LevelInit.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<>, IServerGameDLL> g_SMGlue_IServerGameDLL__LevelShutdown;
inline int SMGlue_MkHook4_IServerGameDLL__LevelShutdown ( fastdelegate::FastDelegate0<> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_IServerGameDLL__LevelShutdown.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameDLL__LevelShutdown ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_IServerGameDLL__LevelShutdown.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<bool, bool>, IServerGameDLL> g_SMGlue_IServerGameDLL__GameFrame;
inline int SMGlue_MkHook4_IServerGameDLL__GameFrame ( fastdelegate::FastDelegate2<bool, bool> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_IServerGameDLL__GameFrame.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameDLL__GameFrame ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_IServerGameDLL__GameFrame.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<bool>, IServerGameDLL> g_SMGlue_IServerGameDLL__Think;
inline int SMGlue_MkHook4_IServerGameDLL__Think ( fastdelegate::FastDelegate1<bool> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_IServerGameDLL__Think.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameDLL__Think ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_IServerGameDLL__Think.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<const char *>, IVEngineServer> g_SMGlue_IVEngineServer__GetMapEntitiesString;
inline int SMGlue_MkHook4_IVEngineServer__GetMapEntitiesString ( fastdelegate::FastDelegate0<const char *> delegate , IVEngineServer * instance, bool post = false ) {return g_SMGlue_IVEngineServer__GetMapEntitiesString.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IVEngineServer__GetMapEntitiesString ( int hk, IVEngineServer * instance, bool post = false ) {g_SMGlue_IVEngineServer__GetMapEntitiesString.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate3<bf_write *, IRecipientFilter *, int, const char *>, IVEngineServer> g_SMGlue_IVEngineServer__UserMessageBegin;
inline int SMGlue_MkHook4_IVEngineServer__UserMessageBegin ( fastdelegate::FastDelegate3<bf_write *, IRecipientFilter *, int, const char *> delegate , IVEngineServer * instance, bool post = false ) {return g_SMGlue_IVEngineServer__UserMessageBegin.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IVEngineServer__UserMessageBegin ( int hk, IVEngineServer * instance, bool post = false ) {g_SMGlue_IVEngineServer__UserMessageBegin.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<>, IVEngineServer> g_SMGlue_IVEngineServer__MessageEnd;
inline int SMGlue_MkHook4_IVEngineServer__MessageEnd ( fastdelegate::FastDelegate0<> delegate , IVEngineServer * instance, bool post = false ) {return g_SMGlue_IVEngineServer__MessageEnd.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IVEngineServer__MessageEnd ( int hk, IVEngineServer * instance, bool post = false ) {g_SMGlue_IVEngineServer__MessageEnd.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<>, IServerGameDLL> g_SMGlue_IServerGameDLL__GameServerSteamAPIActivated;
inline int SMGlue_MkHook4_IServerGameDLL__GameServerSteamAPIActivated ( fastdelegate::FastDelegate0<> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_IServerGameDLL__GameServerSteamAPIActivated.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameDLL__GameServerSteamAPIActivated ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_IServerGameDLL__GameServerSteamAPIActivated.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<const char *>, IServerGameDLL> g_SMGlue_IServerGameDLL__GetGameDescription;
inline int SMGlue_MkHook4_IServerGameDLL__GetGameDescription ( fastdelegate::FastDelegate0<const char *> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_IServerGameDLL__GetGameDescription.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameDLL__GetGameDescription ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_IServerGameDLL__GetGameDescription.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<edict_t *>, IServerGameClients> g_SMGlue_IServerGameClients__ClientVoice;
inline int SMGlue_MkHook4_IServerGameClients__ClientVoice ( fastdelegate::FastDelegate1<edict_t *> delegate , IServerGameClients * instance, bool post = false ) {return g_SMGlue_IServerGameClients__ClientVoice.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IServerGameClients__ClientVoice ( int hk, IServerGameClients * instance, bool post = false ) {g_SMGlue_IServerGameClients__ClientVoice.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate5<IRecipientFilter &, float, const void *, const SendTable *, int>, IVEngineServer> g_SMGlue_IVEngineServer__PlaybackTempEntity;
inline int SMGlue_MkHook4_IVEngineServer__PlaybackTempEntity ( fastdelegate::FastDelegate5<IRecipientFilter &, float, const void *, const SendTable *, int> delegate , IVEngineServer * instance, bool post = false ) {return g_SMGlue_IVEngineServer__PlaybackTempEntity.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IVEngineServer__PlaybackTempEntity ( int hk, IVEngineServer * instance, bool post = false ) {g_SMGlue_IVEngineServer__PlaybackTempEntity.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate3<int, int, bool, bool>, IVoiceServer> g_SMGlue_IVoiceServer__SetClientListening;
inline int SMGlue_MkHook4_IVoiceServer__SetClientListening ( fastdelegate::FastDelegate3<int, int, bool, bool> delegate , IVoiceServer * instance, bool post = false ) {return g_SMGlue_IVoiceServer__SetClientListening.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IVoiceServer__SetClientListening ( int hk, IVoiceServer * instance, bool post = false ) {g_SMGlue_IVoiceServer__SetClientListening.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate8<int, const Vector &, const char *, float, soundlevel_t, int, int, float>, IVEngineServer> g_SMGlue_IVEngineServer__EmitAmbientSound;
inline int SMGlue_MkHook4_IVEngineServer__EmitAmbientSound ( fastdelegate::FastDelegate8<int, const Vector &, const char *, float, soundlevel_t, int, int, float> delegate , IVEngineServer * instance, bool post = false ) {return g_SMGlue_IVEngineServer__EmitAmbientSound.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IVEngineServer__EmitAmbientSound ( int hk, IVEngineServer * instance, bool post = false ) {g_SMGlue_IVEngineServer__EmitAmbientSound.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate15<IRecipientFilter &, int, int, const char *, float, soundlevel_t, int, int, int, const Vector *, const Vector *, CUtlVector<Vector> *, bool, float, int, void>, IEngineSound> g_SMGlue_IEngineSound__EmitSound;
inline int SMGlue_MkHook4_IEngineSound__EmitSound ( fastdelegate::FastDelegate15<IRecipientFilter &, int, int, const char *, float, soundlevel_t, int, int, int, const Vector *, const Vector *, CUtlVector<Vector> *, bool, float, int, void> delegate , IEngineSound * instance, bool post = false ) {return g_SMGlue_IEngineSound__EmitSound.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IEngineSound__EmitSound ( int hk, IEngineSound * instance, bool post = false ) {g_SMGlue_IEngineSound__EmitSound.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate15<IRecipientFilter &, int , int , const char *, float , float , int , int , int , const Vector *, const Vector *, CUtlVector<Vector> *, bool , float , int>, IEngineSound> g_SMGlue_IEngineSound__EmitSound2;
inline int SMGlue_MkHook4_IEngineSound__EmitSound2 ( fastdelegate::FastDelegate15<IRecipientFilter &, int , int , const char *, float , float , int , int , int , const Vector *, const Vector *, CUtlVector<Vector> *, bool , float , int> delegate , IEngineSound * instance, bool post = false ) {return g_SMGlue_IEngineSound__EmitSound2.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IEngineSound__EmitSound2 ( int hk, IEngineSound * instance, bool post = false ) {g_SMGlue_IEngineSound__EmitSound2.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<const char*, const char*, bool>, IBaseFileSystem> g_SMGlue_IBaseFileSystem__FileExists;
inline int SMGlue_MkHook4_IBaseFileSystem__FileExists ( fastdelegate::FastDelegate2<const char*, const char*, bool> delegate , IBaseFileSystem * instance, bool post = false ) {return g_SMGlue_IBaseFileSystem__FileExists.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IBaseFileSystem__FileExists ( int hk, IBaseFileSystem * instance, bool post = false ) {g_SMGlue_IBaseFileSystem__FileExists.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<const char*, unsigned int, bool>, INetChannel> g_SMGlue_INetChannel__SendFile;
inline int SMGlue_MkHook4_INetChannel__SendFile ( fastdelegate::FastDelegate2<const char*, unsigned int, bool> delegate , INetChannel * instance, bool post = false ) {return g_SMGlue_INetChannel__SendFile.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_INetChannel__SendFile ( int hk, INetChannel * instance, bool post = false ) {g_SMGlue_INetChannel__SendFile.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<struct netpacket_s*, bool>, INetChannel> g_SMGlue_INetChannel__ProcessPacket;
inline int SMGlue_MkHook4_INetChannel__ProcessPacket ( fastdelegate::FastDelegate2<struct netpacket_s*, bool> delegate , INetChannel * instance, bool post = false ) {return g_SMGlue_INetChannel__ProcessPacket.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_INetChannel__ProcessPacket ( int hk, INetChannel * instance, bool post = false ) {g_SMGlue_INetChannel__ProcessPacket.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<CLC_VoiceData*, bool>, IClientMessageHandler> g_SMGlue_IClientMessageHandler__ProcessVoiceData;
inline int SMGlue_MkHook4_IClientMessageHandler__ProcessVoiceData ( fastdelegate::FastDelegate1<CLC_VoiceData*, bool> delegate , IClientMessageHandler * instance, bool post = false ) {return g_SMGlue_IClientMessageHandler__ProcessVoiceData.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_IClientMessageHandler__ProcessVoiceData ( int hk, IClientMessageHandler * instance, bool post = false ) {g_SMGlue_IClientMessageHandler__ProcessVoiceData.remove(hk, instance, post ? 1 : 0);}

// /home/god/projects/css_enhanced_clean/sourcemod_metamod_core/metamod.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<bool>, IServerGameDLL> g_SMGlue_P0__SGD_GameInit;
inline int SMGlue_MkHook4_P0__SGD_GameInit ( fastdelegate::FastDelegate0<bool> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_P0__SGD_GameInit.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P0__SGD_GameInit ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_P0__SGD_GameInit.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_metamod_core/metamod.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate6<const char *, const char *, const char *, const char *, bool, bool, bool>, IServerGameDLL> g_SMGlue_P6__SGD_LevelInit;
inline int SMGlue_MkHook4_P6__SGD_LevelInit ( fastdelegate::FastDelegate6<const char *, const char *, const char *, const char *, bool, bool, bool> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_P6__SGD_LevelInit.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P6__SGD_LevelInit ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_P6__SGD_LevelInit.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_metamod_core/metamod.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<void>, IServerGameDLL> g_SMGlue_P0__SGD_LevelShutdown;
inline int SMGlue_MkHook4_P0__SGD_LevelShutdown ( fastdelegate::FastDelegate0<void> delegate , IServerGameDLL * instance, bool post = false ) {return g_SMGlue_P0__SGD_LevelShutdown.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P0__SGD_LevelShutdown ( int hk, IServerGameDLL * instance, bool post = false ) {g_SMGlue_P0__SGD_LevelShutdown.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<CBaseEntity *, void>, CBaseEntity> g_SMGlue_P1__EndTouch;
inline int SMGlue_MkHook4_P1__EndTouch ( fastdelegate::FastDelegate1<CBaseEntity *, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__EndTouch.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__EndTouch ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__EndTouch.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<FireBulletsInfo_t const&, void>, CBaseEntity> g_SMGlue_P1__FireBullets;
inline int SMGlue_MkHook4_P1__FireBullets ( fastdelegate::FastDelegate1<FireBulletsInfo_t const&, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__FireBullets.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__FireBullets ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__FireBullets.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<int>, CBaseEntity> g_SMGlue_P0__GetMaxHealth;
inline int SMGlue_MkHook4_P0__GetMaxHealth ( fastdelegate::FastDelegate0<int> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P0__GetMaxHealth.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P0__GetMaxHealth ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P0__GetMaxHealth.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<void *, void>, CBaseEntity> g_SMGlue_P1__GroundEntChanged;
inline int SMGlue_MkHook4_P1__GroundEntChanged ( fastdelegate::FastDelegate1<void *, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__GroundEntChanged.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__GroundEntChanged ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__GroundEntChanged.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<CTakeDamageInfo &, int>, CBaseEntity> g_SMGlue_P1__OnTakeDamage;
inline int SMGlue_MkHook4_P1__OnTakeDamage ( fastdelegate::FastDelegate1<CTakeDamageInfo &, int> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__OnTakeDamage.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__OnTakeDamage ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__OnTakeDamage.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<CTakeDamageInfo &, int>, CBaseEntity> g_SMGlue_P1__OnTakeDamage_Alive;
inline int SMGlue_MkHook4_P1__OnTakeDamage_Alive ( fastdelegate::FastDelegate1<CTakeDamageInfo &, int> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__OnTakeDamage_Alive.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__OnTakeDamage_Alive ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__OnTakeDamage_Alive.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<void>, CBaseEntity> g_SMGlue_P0__PreThink;
inline int SMGlue_MkHook4_P0__PreThink ( fastdelegate::FastDelegate0<void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P0__PreThink.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P0__PreThink ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P0__PreThink.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<void>, CBaseEntity> g_SMGlue_P0__PostThink;
inline int SMGlue_MkHook4_P0__PostThink ( fastdelegate::FastDelegate0<void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P0__PostThink.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P0__PostThink ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P0__PostThink.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<bool>, CBaseEntity> g_SMGlue_P0__Reload;
inline int SMGlue_MkHook4_P0__Reload ( fastdelegate::FastDelegate0<bool> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P0__Reload.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P0__Reload ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P0__Reload.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<CCheckTransmitInfo *, bool, void>, CBaseEntity> g_SMGlue_P2__SetTransmit;
inline int SMGlue_MkHook4_P2__SetTransmit ( fastdelegate::FastDelegate2<CCheckTransmitInfo *, bool, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P2__SetTransmit.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P2__SetTransmit ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P2__SetTransmit.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<int, int, bool>, CBaseEntity> g_SMGlue_P2__ShouldCollide;
inline int SMGlue_MkHook4_P2__ShouldCollide ( fastdelegate::FastDelegate2<int, int, bool> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P2__ShouldCollide.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P2__ShouldCollide ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P2__ShouldCollide.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<void>, CBaseEntity> g_SMGlue_P0__Spawn;
inline int SMGlue_MkHook4_P0__Spawn ( fastdelegate::FastDelegate0<void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P0__Spawn.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P0__Spawn ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P0__Spawn.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<CBaseEntity *, void>, CBaseEntity> g_SMGlue_P1__StartTouch;
inline int SMGlue_MkHook4_P1__StartTouch ( fastdelegate::FastDelegate1<CBaseEntity *, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__StartTouch.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__StartTouch ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__StartTouch.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<void>, CBaseEntity> g_SMGlue_P0__Think;
inline int SMGlue_MkHook4_P0__Think ( fastdelegate::FastDelegate0<void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P0__Think.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P0__Think ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P0__Think.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<CBaseEntity *, void>, CBaseEntity> g_SMGlue_P1__Touch;
inline int SMGlue_MkHook4_P1__Touch ( fastdelegate::FastDelegate1<CBaseEntity *, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__Touch.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__Touch ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__Touch.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate4<CTakeDamageInfo &, const Vector &, CGameTrace *, CDmgAccumulator *, void>, CBaseEntity> g_SMGlue_P4__TraceAttack;
inline int SMGlue_MkHook4_P4__TraceAttack ( fastdelegate::FastDelegate4<CTakeDamageInfo &, const Vector &, CGameTrace *, CDmgAccumulator *, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P4__TraceAttack.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P4__TraceAttack ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P4__TraceAttack.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate3<CTakeDamageInfo &, const Vector &, CGameTrace *, void>, CBaseEntity> g_SMGlue_P3__TraceAttack;
inline int SMGlue_MkHook4_P3__TraceAttack ( fastdelegate::FastDelegate3<CTakeDamageInfo &, const Vector &, CGameTrace *, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P3__TraceAttack.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P3__TraceAttack ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P3__TraceAttack.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate4<CBaseEntity *, CBaseEntity *, USE_TYPE, float, void>, CBaseEntity> g_SMGlue_P4__Use;
inline int SMGlue_MkHook4_P4__Use ( fastdelegate::FastDelegate4<CBaseEntity *, CBaseEntity *, USE_TYPE, float, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P4__Use.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P4__Use ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P4__Use.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<IPhysicsObject *, void>, CBaseEntity> g_SMGlue_P1__VPhysicsUpdate;
inline int SMGlue_MkHook4_P1__VPhysicsUpdate ( fastdelegate::FastDelegate1<IPhysicsObject *, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__VPhysicsUpdate.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__VPhysicsUpdate ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__VPhysicsUpdate.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<CBaseCombatWeapon *, bool>, CBaseEntity> g_SMGlue_P1__Weapon_CanSwitchTo;
inline int SMGlue_MkHook4_P1__Weapon_CanSwitchTo ( fastdelegate::FastDelegate1<CBaseCombatWeapon *, bool> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__Weapon_CanSwitchTo.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__Weapon_CanSwitchTo ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__Weapon_CanSwitchTo.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<CBaseCombatWeapon *, bool>, CBaseEntity> g_SMGlue_P1__Weapon_CanUse;
inline int SMGlue_MkHook4_P1__Weapon_CanUse ( fastdelegate::FastDelegate1<CBaseCombatWeapon *, bool> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__Weapon_CanUse.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__Weapon_CanUse ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__Weapon_CanUse.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate3<CBaseCombatWeapon *, const Vector *, const Vector *, void>, CBaseEntity> g_SMGlue_P3__Weapon_Drop;
inline int SMGlue_MkHook4_P3__Weapon_Drop ( fastdelegate::FastDelegate3<CBaseCombatWeapon *, const Vector *, const Vector *, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P3__Weapon_Drop.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P3__Weapon_Drop ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P3__Weapon_Drop.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<CBaseCombatWeapon *, void>, CBaseEntity> g_SMGlue_P1__Weapon_Equip;
inline int SMGlue_MkHook4_P1__Weapon_Equip ( fastdelegate::FastDelegate1<CBaseCombatWeapon *, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__Weapon_Equip.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__Weapon_Equip ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__Weapon_Equip.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<CBaseCombatWeapon *, int, bool>, CBaseEntity> g_SMGlue_P2__Weapon_Switch;
inline int SMGlue_MkHook4_P2__Weapon_Switch ( fastdelegate::FastDelegate2<CBaseCombatWeapon *, int, bool> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P2__Weapon_Switch.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P2__Weapon_Switch ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P2__Weapon_Switch.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate1<CBaseEntity *, void>, CBaseEntity> g_SMGlue_P1__Blocked;
inline int SMGlue_MkHook4_P1__Blocked ( fastdelegate::FastDelegate1<CBaseEntity *, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P1__Blocked.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P1__Blocked ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P1__Blocked.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdkhooks/extension.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate0<bool>, CBaseEntity> g_SMGlue_P0__CanBeAutobalanced;
inline int SMGlue_MkHook4_P0__CanBeAutobalanced ( fastdelegate::FastDelegate0<bool> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P0__CanBeAutobalanced.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P0__CanBeAutobalanced ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P0__CanBeAutobalanced.remove(hk, instance, post ? 1 : 0);}
// /home/god/projects/css_enhanced_clean/sourcemod_sdktools/hooks.cpp
GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<CUserCmd *, IMoveHelper *, void>, CUserCmd> g_SMGlue_P2__PlayerRunCmdHook;
inline int SMGlue_MkHook4_P2__PlayerRunCmdHook ( fastdelegate::FastDelegate2<CUserCmd *, IMoveHelper *, void> delegate , CUserCmd * instance, bool post = false ) {return g_SMGlue_P2__PlayerRunCmdHook.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P2__PlayerRunCmdHook ( int hk, CUserCmd * instance, bool post = false ) {g_SMGlue_P2__PlayerRunCmdHook.remove(hk, instance, post ? 1 : 0);}

GLUE_API extern SourcemodRouter<fastdelegate::FastDelegate2<CUserCmd *, IMoveHelper *, void>, CBaseEntity> g_SMGlue_P2__PlayerRunCmdHook2;
inline int SMGlue_MkHook4_P2__PlayerRunCmdHook ( fastdelegate::FastDelegate2<CUserCmd *, IMoveHelper *, void> delegate , CBaseEntity * instance, bool post = false ) {return g_SMGlue_P2__PlayerRunCmdHook2.add(delegate,instance, post ? 1 : 0);}
inline void SMGlue_RmHook4_P2__PlayerRunCmdHook ( int hk, CBaseEntity * instance, bool post = false ) {g_SMGlue_P2__PlayerRunCmdHook2.remove(hk, instance, post ? 1 : 0);}

#define JOIN_(x, y) x ## y
#define JOIN(x, y) JOIN_(x, y)
#define IFACE(x, y) JOIN(JOIN(x, __), y)
#define PRE_MEMBER(x, y) JOIN(HkPre_, IFACE(x, y))
#define POST_MEMBER(x, y) JOIN(HkPost_, IFACE(x, y))
#define PRE_MEMBER_s(x, y, s) JOIN(JOIN(HkPre_, IFACE(x, y)), s)
#define POST_MEMBER_s(x, y, s) JOIN(JOIN(HkPost_, IFACE(x, y)), s)
#define ADD_MEMBER(x, y) JOIN(SMGlue_MkHook4_, IFACE(x, y))
#define REM_MEMBER(x, y) JOIN(SMGlue_RmHook4_, IFACE(x, y))
#define ADD_MANMEMBER(x, y, N) JOIN(SMGlue_MkHook4_P, JOIN(N, JOIN(__, y)))
#define SH_ADD_HOOK_s(iface, member, iface_instance, delegate, is_post, s) (( is_post ) ? (POST_MEMBER_s(iface, member, s) = ADD_MEMBER(iface, member) ( delegate , iface_instance , true )) : (PRE_MEMBER_s(iface, member, s) = ADD_MEMBER(iface, member) ( delegate , iface_instance )))
#define SH_REMOVE_HOOK_s(iface, member, iface_instance, delegate, is_post, s )  if ( is_post ) { REM_MEMBER(iface, member) ( POST_MEMBER_s(iface, member, s), iface_instance , true ) ; } else { (REM_MEMBER(iface, member) ( PRE_MEMBER_s(iface, member, s), iface_instance , true )) ; }
#define SH_ADD_HOOK(iface, member, iface_instance, delegate, is_post) (( is_post ) ? (POST_MEMBER(iface, member) = ADD_MEMBER(iface, member) ( delegate , iface_instance , true )) : (PRE_MEMBER(iface, member) = ADD_MEMBER(iface, member) ( delegate , iface_instance )))
#define SH_REMOVE_HOOK(iface, member, iface_instance, delegate, is_post )  if ( is_post ) { REM_MEMBER(iface, member) ( POST_MEMBER(iface, member), iface_instance , true ) ; } else { REM_MEMBER(iface, member) ( PRE_MEMBER(iface, member), iface_instance , true ) ; }
#define SH_DECL_HOOK0_void(iface, member, unused, unused2) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK0(iface, member, unused, unused2, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK1_void(iface, member, unused, unused2, a0) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK1_void_vafmt(iface, member, unused, unused2, a0) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK1(iface, member, unused, unused2, a0, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK1_vafmt(iface, member, unused, unused2, a0, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK2_void(iface, member, unused, unused2, a0, a1) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK2(iface, member, unused, unused2, a0, a1, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK3_void(iface, member, unused, unused2, a0, a1, a2) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK3(iface, member, unused, unused2, a0, a1, a2, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK4_void(iface, member, unused, unused2, a0, a1, a2, a3) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK4(iface, member, unused, unused2, a0, a1, a2, a3, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK5_void(iface, member, unused, unused2, a0, a1, a2, a3, a4) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK5(iface, member, unused, unused2, a0, a1, a2, a3, a4, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK6_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK6(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK7_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK7(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK8_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK8(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK9_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK9(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK10_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK10(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK11_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK11(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK12_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK12(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK13_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK13(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK14_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK14(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK15_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK15(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK16_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK16(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK17_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK17(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK18_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK18(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK19_void(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);
#define SH_DECL_HOOK19(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, arettype) static int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);

#define SH_DECL_HOOK0_void_s(iface, member, unused, unused2, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK0_s(iface, member, unused, unused2, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK1_void_s(iface, member, unused, unused2, a0, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK1_void_vafmt_s(iface, member, unused, unused2, a0, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK1_s(iface, member, unused, unused2, a0, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK1_vafmt_s(iface, member, unused, unused2, a0, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK2_void_s(iface, member, unused, unused2, a0, a1, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK2_s(iface, member, unused, unused2, a0, a1, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK3_void_s(iface, member, unused, unused2, a0, a1, a2, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK3_s(iface, member, unused, unused2, a0, a1, a2, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK4_void_s(iface, member, unused, unused2, a0, a1, a2, a3, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK4_s(iface, member, unused, unused2, a0, a1, a2, a3, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK5_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK5_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK6_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK6_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK7_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK7_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK8_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK8_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK9_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK9_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK10_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK10_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK11_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK11_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK12_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK12_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK13_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK13_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK14_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK14_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK15_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK15_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK16_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK16_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK17_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK17_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK18_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK18_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK19_void_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);
#define SH_DECL_HOOK19_s(iface, member, unused, unused2, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, arettype, s) static int PRE_MEMBER_s(iface, member, s), POST_MEMBER_s(iface, member, s);

#define SH_ADD_VPHOOK(iface, member, iface_instance, delegate, is_post) (( is_post ) ? (ADD_MEMBER(iface, member) ( delegate , iface_instance , true )) : (ADD_MEMBER(iface, member) ( delegate , iface_instance ))) 
#define SH_ADD_DVPHOOK(iface, member, iface_instance, delegate, is_post) (( is_post ) ? (ADD_MEMBER(iface, member) ( delegate , iface_instance , true )) : (ADD_MEMBER(iface, member) ( delegate , iface_instance )))

#define SH_ADD_HOOK_STATICFUNC(iface, member, iface_instance, delegate, post) SH_ADD_HOOK(iface, member, iface_instance, SH_STATIC(delegate), post)
#define SH_ADD_HOOK_MEMFUNC(iface, member, iface_instance, delegate_thisptr, delegate, is_post) SH_ADD_HOOK(iface, member, iface_instance, SH_MEMBER(delegate_thisptr, delegate), is_post)

#define SH_REMOVE_HOOK_STATICFUNC(iface, member, iface_instance, delegate, post) SH_REMOVE_HOOK(iface, member, iface_instance, SH_STATIC(delegate), post)
#define SH_REMOVE_HOOK_MEMFUNC(iface, member, iface_instance, delegate_thisptr, delegate, is_post) SH_REMOVE_HOOK(iface, member, iface_instance, SH_MEMBER(delegate_thisptr, delegate), is_post)

// TODO
#define SH_ADD_MANUALVPHOOK(hookname, ifaceptr, handler, post) xxx
#define SH_ADD_MANUALDVPHOOK(hookname, ifaceptr, handler, post) xxx
#define SH_REMOVE_HOOK_ID(hookid) xxx
#define SH_REMOVE_HOOK_ID_ALT(iface,member,instance,hk,post) REM_MEMBER(iface, member) ( hk, instance , post )


#define SH_DECL_MANUALHOOK0(...)
#define SH_DECL_MANUALHOOK0_void(...)
#define SH_DECL_MANUALHOOK1(...)
#define SH_DECL_MANUALHOOK1_void(...)
#define SH_DECL_MANUALHOOK2(...)
#define SH_DECL_MANUALHOOK2_void(...)
#define SH_DECL_MANUALHOOK3(...)
#define SH_DECL_MANUALHOOK3_void(...)
#define SH_DECL_MANUALHOOK4(...)
#define SH_DECL_MANUALHOOK4_void(...)
#define SH_DECL_MANUALHOOK5(...)
#define SH_DECL_MANUALHOOK5_void(...)
#define SH_DECL_MANUALHOOK6(...)
#define SH_DECL_MANUALHOOK6_void(...)
#define SH_DECL_MANUALHOOK7(...)
#define SH_DECL_MANUALHOOK7_void(...)
#define SH_DECL_MANUALHOOK8(...)
#define SH_DECL_MANUALHOOK8_void(...)
#define SH_DECL_MANUALHOOK9(...)
#define SH_DECL_MANUALHOOK9_void(...)
#define SH_DECL_MANUALHOOK10(...)
#define SH_DECL_MANUALHOOK10_void(...)
#define SH_DECL_MANUALHOOK11(...)
#define SH_DECL_MANUALHOOK11_void(...)
#define SH_DECL_MANUALHOOK12(...)
#define SH_DECL_MANUALHOOK12_void(...)
#define SH_DECL_MANUALHOOK13(...)
#define SH_DECL_MANUALHOOK13_void(...)
#define SH_DECL_MANUALHOOK14(...)
#define SH_DECL_MANUALHOOK14_void(...)
#define SH_DECL_MANUALHOOK15(...)
#define SH_DECL_MANUALHOOK15_void(...)
#define SH_DECL_MANUALHOOK16(...)
#define SH_DECL_MANUALHOOK16_void(...)
#define SH_DECL_MANUALHOOK17(...)
#define SH_DECL_MANUALHOOK17_void(...)
#define SH_DECL_MANUALHOOK18(...)
#define SH_DECL_MANUALHOOK18_void(...)
#define SH_DECL_MANUALHOOK19(...)
#define SH_DECL_MANUALHOOK19_void(...)

#define SH_ADD_MANUALVPHOOK(name,instance,delegate,is_post) (( is_post ) ? (ADD_MANMEMBER(iface, name, N) ( delegate , instance , true )) : (ADD_MANMEMBER(iface, name, N) ( delegate , instance )))
#define SH_ADD_MANUALVPHOOK_N(name,instance,delegate,is_post,N) (( is_post ) ? (ADD_MANMEMBER(iface, name, N) ( delegate , instance , true )) : (ADD_MANMEMBER(iface, name, N) ( delegate , instance )))
        // hookid = SH_ADD_MANUALVPHOOK(EndTouch, pEnt, SH_MEMBER(&g_Interface, &SDKHooks::Hook_EndTouch), false);

#endif // !GLUE_HPP