#pragma once

// #include "iserverplugin.h"
#include "tier1/convar.h"
#include "filesystem.h"
#include "protocol.h"
#ifndef GLUE_HPP
#define GLUE_HPP

#include "../sourcemod_metamod_core/sourcehook/FastDelegate.h"

#define PLAYERLOCALDATA_H
#define CBASEPLAYER_HIDE_INLINE
#include "router.hpp"
#include "igameevents.h"
#include "ivoiceserver.h"
#include "eiface.h"
#include "engine/IEngineSound.h"

class CBaseCombatWeapon;
class CBaseEntity;
class CBaseEntityOutput;
class CCSGameRules;
class CCSPlayer;
class CCSWeaponInfo;
class CDmgAccumulator;
class CLC_VoiceData;
class CPredictableId;
class CTakeDamageInfo;
class CUserCmd;
class IClientMessageHandler;
class IEntityListener2;
class IEntityListener;
class INetChannel;
class IPhysicsObject;
class IServerPluginCallbacks;
class IServerPluginHelpers;

struct FireBulletsInfo_t;
#ifndef USE_TYPE_DEFINED
typedef int USE_TYPE;
#endif

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

#include "iface.hpp"

extern SourcemodRouter< fastdelegate::FastDelegate4<CBaseEntityOutput*,CBaseEntity*, CBaseEntity*, float>, CBaseEntityOutput > g_SMGlue_COutputEvent__FireOutput;
template <typename T> inline int SMGlue_MkHook4_FireOutput ( fastdelegate::FastDelegate4<CBaseEntityOutput*,CBaseEntity*, CBaseEntity*, float> delegate , T * instance, bool post = false ) {return g_SMGlue_COutputEvent__FireOutput.add(delegate, instance, post ? 1 : 0);}
template <typename T> inline void SMGlue_RmHook4_FireOutput ( int hk, T * instance, bool post = false ) {g_SMGlue_COutputEvent__FireOutput.remove(hk,instance,post ? 1 : 0);}

// CCSWeaponInfo::GetWeaponPrice
extern SourcemodRouter< fastdelegate::FastDelegate1<CCSWeaponInfo*, int>, CCSWeaponInfo > g_SMGlue_CCSWeaponInfo__GetWeaponPrice;
// CCSPlayer::HandleCommand_Buy_Internal
extern SourcemodRouter< fastdelegate::FastDelegate2<CCSPlayer*,const char*>, CCSPlayer > g_SMGlue_CCSPlayer__HandleCommand_Buy_Internal;
// CCSGameRules::TerminateRound
extern SourcemodRouter< fastdelegate::FastDelegate3<CCSGameRules*, float, int>, CCSGameRules > g_SMGlue_CCSGameRules__TerminateRound;
// bool CCSPlayer::CSWeaponDrop( CBaseCombatWeapon *pWeapon, bool bDropShield, bool bThrowForward )
extern SourcemodRouter< fastdelegate::FastDelegate4<CCSPlayer*,CBaseCombatWeapon*,bool,bool>, CCSPlayer > g_SMGlue_CCSPlayer__CSWeaponDrop;

template <typename T> inline int SMGlue_MkHook4_ConCommand__Dispatch ( fastdelegate::FastDelegate1<CCommand *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_ConCommand__Dispatch(delegate, instance, post);}
template <typename T> inline int SMGlue_MkHook4_IBaseFileSystem__FileExists ( fastdelegate::FastDelegate2<const char*, const char*, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IBaseFileSystem__FileExists(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IClientMessageHandler__ProcessVoiceData ( fastdelegate::FastDelegate1<CLC_VoiceData*, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IClientMessageHandler__ProcessVoiceData(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_ICvar__CallGlobalChangeCallback ( fastdelegate::FastDelegate2<ConVar *, const char *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_ICvar__CallGlobalChangeCallback(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_ICvar__CallGlobalChangeCallbacks ( fastdelegate::FastDelegate3<ConVar *, const char *, float> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_ICvar__CallGlobalChangeCallbacks(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_ICvar__RegisterConCommand ( fastdelegate::FastDelegate1<ConCommandBase *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_ICvar__RegisterConCommand(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_ICvar__UnregisterConCommand ( fastdelegate::FastDelegate1<ConCommandBase *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_ICvar__UnregisterConCommand(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IEngineSound__EmitSound ( fastdelegate::FastDelegate15<IRecipientFilter *, int, int, const char *, float, soundlevel_t, int, int, int, Vector *, Vector *, CUtlVector<Vector> *, bool, float, int, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IEngineSound__EmitSound(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IEngineSound__EmitSound2 ( fastdelegate::FastDelegate15<IRecipientFilter *, int , int , const char *, float , float , int , int , int , Vector *, Vector *, CUtlVector<Vector> *, bool , float , int> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IEngineSound__EmitSound2(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IGameEventManager2__FireEvent ( fastdelegate::FastDelegate2<IGameEvent *, bool, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IGameEventManager2__FireEvent(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_INetChannel__ProcessPacket ( fastdelegate::FastDelegate2<struct netpacket_s*, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_INetChannel__ProcessPacket(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_INetChannel__SendFile ( fastdelegate::FastDelegate2<const char*, unsigned int, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_INetChannel__SendFile(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameClients__ClientCommand ( fastdelegate::FastDelegate2<edict_t *, CCommand *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameClients__ClientCommand(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameClients__ClientCommandKeyValues ( fastdelegate::FastDelegate2<edict_t *, KeyValues *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameClients__ClientCommandKeyValues(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameClients__ClientConnect ( fastdelegate::FastDelegate5<edict_t *, const char *, const char *, char *, int, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameClients__ClientConnect(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameClients__ClientDisconnect ( fastdelegate::FastDelegate1<edict_t *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameClients__ClientDisconnect(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameClients__ClientPutInServer ( fastdelegate::FastDelegate2<edict_t *, const char *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameClients__ClientPutInServer(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameClients__ClientSettingsChanged ( fastdelegate::FastDelegate1<edict_t *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameClients__ClientSettingsChanged(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameClients__ClientVoice ( fastdelegate::FastDelegate1<edict_t *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameClients__ClientVoice(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameClients__SetCommandClient ( fastdelegate::FastDelegate1<int> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameClients__SetCommandClient(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameDLL__GameFrame ( fastdelegate::FastDelegate2<bool, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameDLL__GameFrame(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameDLL__GameServerSteamAPIActivated ( fastdelegate::FastDelegate0<> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameDLL__GameServerSteamAPIActivated(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameDLL__GetGameDescription ( fastdelegate::FastDelegate0<const char *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameDLL__GetGameDescription(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameDLL__LevelInit ( fastdelegate::FastDelegate6<const char *, const char *, const char *, const char *, bool, bool, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameDLL__LevelInit(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameDLL__LevelShutdown ( fastdelegate::FastDelegate0<> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameDLL__LevelShutdown(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameDLL__OnQueryCvarValueFinished ( fastdelegate::FastDelegate5<QueryCvarCookie_t, edict_t *, EQueryCvarValueStatus, const char *, const char *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameDLL__OnQueryCvarValueFinished(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameDLL__ServerActivate ( fastdelegate::FastDelegate3<edict_t *, int, int> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameDLL__ServerActivate(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameDLL__ServerHibernationUpdate ( fastdelegate::FastDelegate1<bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameDLL__ServerHibernationUpdate(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameDLL__SetServerHibernation ( fastdelegate::FastDelegate1<bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameDLL__SetServerHibernation(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerGameDLL__Think ( fastdelegate::FastDelegate1<bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerGameDLL__Think(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerPluginCallbacks__OnQueryCvarValueFinished ( fastdelegate::FastDelegate5<QueryCvarCookie_t, edict_t *, EQueryCvarValueStatus, const char *, const char *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerPluginCallbacks__OnQueryCvarValueFinished(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IServerPluginHelpers__CreateMessage ( fastdelegate::FastDelegate4<edict_t *, DIALOG_TYPE, KeyValues *, IServerPluginCallbacks *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IServerPluginHelpers__CreateMessage(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IVEngineServer__ChangeLevel ( fastdelegate::FastDelegate2<const char *, const char *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IVEngineServer__ChangeLevel(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IVEngineServer__ClientCommand ( fastdelegate::FastDelegate2<edict_t *, const char*> delegate, T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IVEngineServer__ClientCommand(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IVEngineServer__ClientPrintf ( fastdelegate::FastDelegate2<edict_t *, const char *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IVEngineServer__ClientPrintf(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IVEngineServer__EmitAmbientSound ( fastdelegate::FastDelegate8<int, Vector *, const char *, float, soundlevel_t, int, int, float> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IVEngineServer__EmitAmbientSound(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IVEngineServer__GetMapEntitiesString ( fastdelegate::FastDelegate0<const char *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IVEngineServer__GetMapEntitiesString(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IVEngineServer__LogPrint ( fastdelegate::FastDelegate1<const char *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IVEngineServer__LogPrint(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IVEngineServer__MessageEnd ( fastdelegate::FastDelegate0<> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IVEngineServer__MessageEnd(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IVEngineServer__PlaybackTempEntity ( fastdelegate::FastDelegate5<IRecipientFilter *, float, const void *, SendTable *, int> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IVEngineServer__PlaybackTempEntity(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IVEngineServer__UserMessageBegin ( fastdelegate::FastDelegate2< IRecipientFilter *, int, bf_write *> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IVEngineServer__UserMessageBegin(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_IVoiceServer__SetClientListening ( fastdelegate::FastDelegate3<int, int, bool, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_IVoiceServer__SetClientListening(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P0__CanBeAutobalanced ( fastdelegate::FastDelegate0<bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P0__CanBeAutobalanced(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P0__GetMaxHealth ( fastdelegate::FastDelegate0<int> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P0__GetMaxHealth(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P0__PostThink ( fastdelegate::FastDelegate0<void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P0__PostThink(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P0__PreThink ( fastdelegate::FastDelegate0<void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P0__PreThink(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P0__Reload ( fastdelegate::FastDelegate0<bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P0__Reload(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P0__SGD_GameInit ( fastdelegate::FastDelegate0<bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P0__SGD_GameInit(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P0__Spawn ( fastdelegate::FastDelegate0<void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P0__Spawn(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P0__Think ( fastdelegate::FastDelegate0<void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P0__Think(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__Blocked ( fastdelegate::FastDelegate1<CBaseEntity *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__Blocked(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__EndTouch ( fastdelegate::FastDelegate1<CBaseEntity *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__EndTouch(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__FireBullets ( fastdelegate::FastDelegate1<FireBulletsInfo_t *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__FireBullets(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__GroundEntChanged ( fastdelegate::FastDelegate1<void *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__GroundEntChanged(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__OnTakeDamage ( fastdelegate::FastDelegate1<CTakeDamageInfo *, int> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__OnTakeDamage(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__OnTakeDamage_Alive ( fastdelegate::FastDelegate1<CTakeDamageInfo *, int> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__OnTakeDamage_Alive(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__StartTouch ( fastdelegate::FastDelegate1<CBaseEntity *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__StartTouch(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__Touch ( fastdelegate::FastDelegate1<CBaseEntity *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__Touch(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__VPhysicsUpdate ( fastdelegate::FastDelegate1<IPhysicsObject *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__VPhysicsUpdate(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__Weapon_CanSwitchTo ( fastdelegate::FastDelegate1<CBaseCombatWeapon *, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__Weapon_CanSwitchTo(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__Weapon_CanUse ( fastdelegate::FastDelegate1<CBaseCombatWeapon *, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__Weapon_CanUse(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P1__Weapon_Equip ( fastdelegate::FastDelegate1<CBaseCombatWeapon *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P1__Weapon_Equip(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P2__PlayerRunCmdHook ( fastdelegate::FastDelegate2<CUserCmd *, IMoveHelper *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P2__PlayerRunCmdHook(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P2__SetTransmit ( fastdelegate::FastDelegate2<CCheckTransmitInfo *, bool, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P2__SetTransmit(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P2__ShouldCollide ( fastdelegate::FastDelegate2<int, int, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P2__ShouldCollide(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P2__Weapon_Switch ( fastdelegate::FastDelegate2<CBaseCombatWeapon *, int, bool> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P2__Weapon_Switch(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P3__TraceAttack ( fastdelegate::FastDelegate3<CTakeDamageInfo *, Vector *, CGameTrace *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P3__TraceAttack(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P3__Weapon_Drop ( fastdelegate::FastDelegate3<CBaseCombatWeapon *, const Vector *, const Vector *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P3__Weapon_Drop(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P4__TraceAttack ( fastdelegate::FastDelegate4<CTakeDamageInfo *, Vector *, CGameTrace *, CDmgAccumulator *, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P4__TraceAttack(delegate,instance,post);}
template <typename T> inline int SMGlue_MkHook4_P4__Use ( fastdelegate::FastDelegate4<CBaseEntity *, CBaseEntity *, USE_TYPE, float, void> delegate , T * instance, bool post = false ) {return instance->GetSourcemodGlue()->SMGlue_MkHook4_P4__Use(delegate,instance,post);}

template <typename T> inline void SMGlue_RmHook4_ConCommand__Dispatch ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_ConCommand__Dispatch(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IBaseFileSystem__FileExists ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IBaseFileSystem__FileExists(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IClientMessageHandler__ProcessVoiceData ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IClientMessageHandler__ProcessVoiceData(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_ICvar__CallGlobalChangeCallback ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_ICvar__CallGlobalChangeCallback(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_ICvar__CallGlobalChangeCallbacks ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_ICvar__CallGlobalChangeCallbacks(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_ICvar__RegisterConCommand ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_ICvar__RegisterConCommand(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_ICvar__UnregisterConCommand ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_ICvar__UnregisterConCommand(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IEngineSound__EmitSound ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IEngineSound__EmitSound(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IEngineSound__EmitSound2 ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IEngineSound__EmitSound2(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IGameEventManager2__FireEvent ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IGameEventManager2__FireEvent(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_INetChannel__ProcessPacket ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_INetChannel__ProcessPacket(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_INetChannel__SendFile ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_INetChannel__SendFile(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameClients__ClientCommand ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameClients__ClientCommand(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameClients__ClientCommandKeyValues ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameClients__ClientCommandKeyValues(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameClients__ClientConnect ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameClients__ClientConnect(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameClients__ClientDisconnect ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameClients__ClientDisconnect(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameClients__ClientPutInServer ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameClients__ClientPutInServer(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameClients__ClientSettingsChanged ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameClients__ClientSettingsChanged(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameClients__ClientVoice ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameClients__ClientVoice(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameClients__SetCommandClient ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameClients__SetCommandClient(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameDLL__GameFrame ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameDLL__GameFrame(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameDLL__GameServerSteamAPIActivated ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameDLL__GameServerSteamAPIActivated(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameDLL__GetGameDescription ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameDLL__GetGameDescription(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameDLL__LevelInit ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameDLL__LevelInit(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameDLL__LevelShutdown ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameDLL__LevelShutdown(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameDLL__OnQueryCvarValueFinished ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameDLL__OnQueryCvarValueFinished(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameDLL__ServerActivate ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameDLL__ServerActivate(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameDLL__ServerHibernationUpdate ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameDLL__ServerHibernationUpdate(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameDLL__SetServerHibernation ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameDLL__SetServerHibernation(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerGameDLL__Think ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerGameDLL__Think(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerPluginCallbacks__OnQueryCvarValueFinished ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerPluginCallbacks__OnQueryCvarValueFinished(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IServerPluginHelpers__CreateMessage ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IServerPluginHelpers__CreateMessage(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IVEngineServer__ChangeLevel ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IVEngineServer__ChangeLevel(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IVEngineServer__ClientCommand ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IVEngineServer__ClientCommand(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IVEngineServer__ClientPrintf ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IVEngineServer__ClientPrintf(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IVEngineServer__EmitAmbientSound ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IVEngineServer__EmitAmbientSound(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IVEngineServer__GetMapEntitiesString ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IVEngineServer__GetMapEntitiesString(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IVEngineServer__LogPrint ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IVEngineServer__LogPrint(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IVEngineServer__MessageEnd ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IVEngineServer__MessageEnd(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IVEngineServer__PlaybackTempEntity ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IVEngineServer__PlaybackTempEntity(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IVEngineServer__UserMessageBegin ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IVEngineServer__UserMessageBegin(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_IVoiceServer__SetClientListening ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_IVoiceServer__SetClientListening(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P0__CanBeAutobalanced ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P0__CanBeAutobalanced(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P0__GetMaxHealth ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P0__GetMaxHealth(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P0__PostThink ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P0__PostThink(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P0__PreThink ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P0__PreThink(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P0__Reload ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P0__Reload(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P0__SGD_GameInit ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P0__SGD_GameInit(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P0__Spawn ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P0__Spawn(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P0__Think ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P0__Think(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__Blocked ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__Blocked(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__EndTouch ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__EndTouch(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__FireBullets ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__FireBullets(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__GroundEntChanged ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__GroundEntChanged(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__OnTakeDamage ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__OnTakeDamage(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__OnTakeDamage_Alive ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__OnTakeDamage_Alive(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__StartTouch ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__StartTouch(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__Touch ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__Touch(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__VPhysicsUpdate ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__VPhysicsUpdate(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__Weapon_CanSwitchTo ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__Weapon_CanSwitchTo(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__Weapon_CanUse ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__Weapon_CanUse(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P1__Weapon_Equip ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P1__Weapon_Equip(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P2__PlayerRunCmdHook ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P2__PlayerRunCmdHook(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P2__SetTransmit ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P2__SetTransmit(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P2__ShouldCollide ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P2__ShouldCollide(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P2__Weapon_Switch ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P2__Weapon_Switch(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P3__TraceAttack ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P3__TraceAttack(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P3__Weapon_Drop ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P3__Weapon_Drop(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P4__TraceAttack ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P4__TraceAttack(hk,instance,post);}
template <typename T> inline void SMGlue_RmHook4_P4__Use ( int hk, T * instance, bool post = false ) {instance->GetSourcemodGlue()->SMGlue_RmHook4_P4__Use(hk,instance,post);}

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
    
#define RETURN_META(result)					xxx
#define RETURN_META_VALUE(result, value)	xxx


#define SH_MANUALHOOK_RECONFIGURE(...) xxx
#define SH_ADD_MANUALHOOK_STATICFUNC(...) xxx

#endif // !GLUE_HPP