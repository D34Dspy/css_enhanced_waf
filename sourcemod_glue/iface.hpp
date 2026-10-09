#ifndef CSOURCEMOD_GLUE_H_
#define CSOURCEMOD_GLUE_H_

#ifndef GLUE_HPP
#error dont include this file
#endif

class IGlobalSourcemodGlueInterface 
{
public:
	virtual void CCSGameRules__TerminateRoundOriginal(CCSGameRules* pGameRules, float delay, int reason) = 0;
	virtual int CCSWeaponInfo__GetWeaponPriceOriginal(CCSWeaponInfo* pWeaponInfo) = 0;
};

class CSourcemodGlueInterface
{
  public:
	SourcemodRouter< fastdelegate::FastDelegate0<>, IServerGameDLL >
	  l_SMGlue_IServerGameDLL__GameServerSteamAPIActivated;
	SourcemodRouter< fastdelegate::FastDelegate0<>, IServerGameDLL > l_SMGlue_IServerGameDLL__LevelShutdown;
	SourcemodRouter< fastdelegate::FastDelegate0<>, IVEngineServer > l_SMGlue_IVEngineServer__MessageEnd;
	SourcemodRouter< fastdelegate::FastDelegate0< bool >, CBaseEntity > l_SMGlue_P0__CanBeAutobalanced;
	SourcemodRouter< fastdelegate::FastDelegate0< bool >, CBaseEntity > l_SMGlue_P0__Reload;
	SourcemodRouter< fastdelegate::FastDelegate0< bool >, IServerGameDLL > l_SMGlue_P0__SGD_GameInit;
	SourcemodRouter< fastdelegate::FastDelegate0< const char* >, IServerGameDLL >
	  l_SMGlue_IServerGameDLL__GetGameDescription;
	SourcemodRouter< fastdelegate::FastDelegate0< const char* >, IVEngineServer >
	  l_SMGlue_IVEngineServer__GetMapEntitiesString;
	SourcemodRouter< fastdelegate::FastDelegate0< int >, CBaseEntity > l_SMGlue_P0__GetMaxHealth;
	SourcemodRouter< fastdelegate::FastDelegate0< void >, CBaseEntity > l_SMGlue_P0__PostThink;
	SourcemodRouter< fastdelegate::FastDelegate0< void >, CBaseEntity > l_SMGlue_P0__PreThink;
	SourcemodRouter< fastdelegate::FastDelegate0< void >, CBaseEntity > l_SMGlue_P0__Spawn;
	SourcemodRouter< fastdelegate::FastDelegate0< void >, CBaseEntity > l_SMGlue_P0__Think;
	SourcemodRouter< fastdelegate::FastDelegate15< IRecipientFilter*,
												   int,
												   int,
												   const char*,
												   float,
												   float,
												   int,
												   int,
												   int,
												   Vector*,
												   Vector*,
												   CUtlVector< Vector >*,
												   bool,
												   float,
												   int >,
					 IEngineSound >
	  l_SMGlue_IEngineSound__EmitSound2;
	SourcemodRouter< fastdelegate::FastDelegate15< IRecipientFilter*,
												   int,
												   int,
												   const char*,
												   float,
												   soundlevel_t,
												   int,
												   int,
												   int,
												   Vector*,
												   Vector*,
												   CUtlVector< Vector >*,
												   bool,
												   float,
												   int,
												   void >,
					 IEngineSound >
	  l_SMGlue_IEngineSound__EmitSound;
	SourcemodRouter< fastdelegate::FastDelegate1< CBaseCombatWeapon*, bool >, CBaseEntity >
	  l_SMGlue_P1__Weapon_CanSwitchTo;
	SourcemodRouter< fastdelegate::FastDelegate1< CBaseCombatWeapon*, bool >, CBaseEntity > l_SMGlue_P1__Weapon_CanUse;
	SourcemodRouter< fastdelegate::FastDelegate1< CBaseCombatWeapon*, void >, CBaseEntity > l_SMGlue_P1__Weapon_Equip;
	SourcemodRouter< fastdelegate::FastDelegate1< CBaseEntity*, void >, CBaseEntity > l_SMGlue_P1__Blocked;
	SourcemodRouter< fastdelegate::FastDelegate1< CBaseEntity*, void >, CBaseEntity > l_SMGlue_P1__EndTouch;
	SourcemodRouter< fastdelegate::FastDelegate1< CBaseEntity*, void >, CBaseEntity > l_SMGlue_P1__StartTouch;
	SourcemodRouter< fastdelegate::FastDelegate1< CBaseEntity*, void >, CBaseEntity > l_SMGlue_P1__Touch;
	SourcemodRouter< fastdelegate::FastDelegate1< CCommand* >, ConCommand > l_SMGlue_ConCommand__Dispatch;
	SourcemodRouter< fastdelegate::FastDelegate1< CLC_VoiceData*, bool >, IClientMessageHandler >
	  l_SMGlue_IClientMessageHandler__ProcessVoiceData;
	SourcemodRouter< fastdelegate::FastDelegate1< CTakeDamageInfo*, int >, CBaseEntity > l_SMGlue_P1__OnTakeDamage;
	SourcemodRouter< fastdelegate::FastDelegate1< CTakeDamageInfo*, int >, CBaseEntity > l_SMGlue_P1__OnTakeDamage_Alive;
	SourcemodRouter< fastdelegate::FastDelegate1< ConCommandBase* >, ICvar > l_SMGlue_ICvar__RegisterConCommand;
	SourcemodRouter< fastdelegate::FastDelegate1< ConCommandBase* >, ICvar > l_SMGlue_ICvar__UnregisterConCommand;
	SourcemodRouter< fastdelegate::FastDelegate1< FireBulletsInfo_t*, int >, CBaseEntity > l_SMGlue_P1__FireBullets;
	SourcemodRouter< fastdelegate::FastDelegate1< IPhysicsObject*, void >, CBaseEntity > l_SMGlue_P1__VPhysicsUpdate;
	SourcemodRouter< fastdelegate::FastDelegate1< bool >, IServerGameDLL >
	  l_SMGlue_IServerGameDLL__ServerHibernationUpdate;
	SourcemodRouter< fastdelegate::FastDelegate1< bool >, IServerGameDLL > l_SMGlue_IServerGameDLL__SetServerHibernation;
	SourcemodRouter< fastdelegate::FastDelegate1< bool >, IServerGameDLL > l_SMGlue_IServerGameDLL__Think;
	SourcemodRouter< fastdelegate::FastDelegate1< const char* >, IVEngineServer > l_SMGlue_IVEngineServer__LogPrint;
	SourcemodRouter< fastdelegate::FastDelegate1< edict_t* >, IServerGameClients >
	  l_SMGlue_IServerGameClients__ClientDisconnect;
	SourcemodRouter< fastdelegate::FastDelegate1< edict_t* >, IServerGameClients >
	  l_SMGlue_IServerGameClients__ClientSettingsChanged;
	SourcemodRouter< fastdelegate::FastDelegate1< edict_t* >, IServerGameClients >
	  l_SMGlue_IServerGameClients__ClientVoice;
	SourcemodRouter< fastdelegate::FastDelegate1< int >, IServerGameClients >
	  l_SMGlue_IServerGameClients__SetCommandClient;
	SourcemodRouter< fastdelegate::FastDelegate1< void*, void >, CBaseEntity > l_SMGlue_P1__GroundEntChanged;
	SourcemodRouter< fastdelegate::FastDelegate2< IRecipientFilter*, int, bf_write* >, IVEngineServer >
	  l_SMGlue_IVEngineServer__UserMessageBegin;
	SourcemodRouter< fastdelegate::FastDelegate2< CBaseCombatWeapon*, int, bool >, CBaseEntity >
	  l_SMGlue_P2__Weapon_Switch;
	SourcemodRouter< fastdelegate::FastDelegate2< CCheckTransmitInfo*, bool, void >, CBaseEntity >
	  l_SMGlue_P2__SetTransmit;
	SourcemodRouter< fastdelegate::FastDelegate2< CUserCmd*, IMoveHelper*, void >, CBaseEntity >
	  l_SMGlue_P2__PlayerRunCmdHook2;
	SourcemodRouter< fastdelegate::FastDelegate2< ConVar*, const char* >, ICvar >
	  l_SMGlue_ICvar__CallGlobalChangeCallback;
	SourcemodRouter< fastdelegate::FastDelegate2< IGameEvent*, bool, bool >, IGameEventManager2 >
	  l_SMGlue_IGameEventManager2__FireEvent;
	SourcemodRouter< fastdelegate::FastDelegate2< bool, bool >, IServerGameDLL > l_SMGlue_IServerGameDLL__GameFrame;
	SourcemodRouter< fastdelegate::FastDelegate2< const char*, const char* >, IVEngineServer >
	  l_SMGlue_IVEngineServer__ChangeLevel;
	SourcemodRouter< fastdelegate::FastDelegate2< const char*, const char*, bool >, IBaseFileSystem >
	  l_SMGlue_IBaseFileSystem__FileExists;
	SourcemodRouter< fastdelegate::FastDelegate2< const char*, unsigned int, bool >, INetChannel >
	  l_SMGlue_INetChannel__SendFile;
	SourcemodRouter< fastdelegate::FastDelegate2< edict_t*, CCommand* >, IServerGameClients >
	  l_SMGlue_IServerGameClients__ClientCommand;
	SourcemodRouter< fastdelegate::FastDelegate2< edict_t*, KeyValues* >, IServerGameClients >
	  l_SMGlue_IServerGameClients__ClientCommandKeyValues;
	SourcemodRouter< fastdelegate::FastDelegate2< edict_t*, const char* >, IServerGameClients >
	  l_SMGlue_IServerGameClients__ClientPutInServer;
	SourcemodRouter< fastdelegate::FastDelegate2< edict_t*, const char* >, IVEngineServer >
	  l_SMGlue_IVEngineServer__ClientPrintf;
	SourcemodRouter< fastdelegate::FastDelegate2< edict_t*, const char* >, IVEngineServer >
	  l_SMGlue_IVEngineServer__ClientCommand;
	SourcemodRouter< fastdelegate::FastDelegate2< int, int, bool >, CBaseEntity > l_SMGlue_P2__ShouldCollide;
	SourcemodRouter< fastdelegate::FastDelegate2< struct netpacket_s*, bool >, INetChannel >
	  l_SMGlue_INetChannel__ProcessPacket;
	SourcemodRouter< fastdelegate::FastDelegate3< CBaseCombatWeapon*, const Vector*, const Vector*, void >, CBaseEntity >
	  l_SMGlue_P3__Weapon_Drop;
	SourcemodRouter< fastdelegate::FastDelegate3< CTakeDamageInfo*, Vector*, CGameTrace*, void >, CBaseEntity >
	  l_SMGlue_P3__TraceAttack;
	SourcemodRouter< fastdelegate::FastDelegate3< ConVar*, const char*, float >, ICvar >
	  l_SMGlue_ICvar__CallGlobalChangeCallbacks;
	SourcemodRouter< fastdelegate::FastDelegate3< edict_t*, int, int >, IServerGameDLL >
	  l_SMGlue_IServerGameDLL__ServerActivate;
	SourcemodRouter< fastdelegate::FastDelegate3< int, int, bool, bool >, IVoiceServer >
	  l_SMGlue_IVoiceServer__SetClientListening;
	SourcemodRouter< fastdelegate::FastDelegate4< CBaseEntity*, CBaseEntity*, USE_TYPE, float, void >, CBaseEntity >
	  l_SMGlue_P4__Use;
	SourcemodRouter< fastdelegate::FastDelegate4< CTakeDamageInfo*, Vector*, CGameTrace*, CDmgAccumulator*, void >,
					 CBaseEntity >
	  l_SMGlue_P4__TraceAttack;
	SourcemodRouter< fastdelegate::FastDelegate4< edict_t*, DIALOG_TYPE, KeyValues*, IServerPluginCallbacks* >,
					 IServerPluginHelpers >
	  l_SMGlue_IServerPluginHelpers__CreateMessage;
	SourcemodRouter< fastdelegate::FastDelegate5< IRecipientFilter*, float, const void*, SendTable*, int >,
					 IVEngineServer >
	  l_SMGlue_IVEngineServer__PlaybackTempEntity;
	SourcemodRouter<
	  fastdelegate::FastDelegate5< QueryCvarCookie_t, edict_t*, EQueryCvarValueStatus, const char*, const char* >,
	  IServerGameDLL >
	  l_SMGlue_IServerGameDLL__OnQueryCvarValueFinished;
	SourcemodRouter<
	  fastdelegate::FastDelegate5< QueryCvarCookie_t, edict_t*, EQueryCvarValueStatus, const char*, const char* >,
	  IServerPluginCallbacks >
	  l_SMGlue_IServerPluginCallbacks__OnQueryCvarValueFinished;
	SourcemodRouter< fastdelegate::FastDelegate5< edict_t*, const char*, const char*, char*, int, bool >,
					 IServerGameClients >
	  l_SMGlue_IServerGameClients__ClientConnect;
	SourcemodRouter< fastdelegate::FastDelegate6< const char*, const char*, const char*, const char*, bool, bool, bool >,
					 IServerGameDLL >
	  l_SMGlue_IServerGameDLL__LevelInit;
	SourcemodRouter< fastdelegate::FastDelegate8< int, Vector*, const char*, float, soundlevel_t, int, int, float >,
					 IVEngineServer >
	  l_SMGlue_IVEngineServer__EmitAmbientSound;

	inline int SMGlue_MkHook4_ConCommand__Dispatch( fastdelegate::FastDelegate1< CCommand* > delegate,
													ConCommand* instance,
													bool post = false )
	{
		return l_SMGlue_ConCommand__Dispatch.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IBaseFileSystem__FileExists(
	  fastdelegate::FastDelegate2< const char*, const char*, bool > delegate,
	  IBaseFileSystem* instance,
	  bool post = false )
	{
		return l_SMGlue_IBaseFileSystem__FileExists.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IClientMessageHandler__ProcessVoiceData(
	  fastdelegate::FastDelegate1< CLC_VoiceData*, bool > delegate,
	  IClientMessageHandler* instance,
	  bool post = false )
	{
		return l_SMGlue_IClientMessageHandler__ProcessVoiceData.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_ICvar__CallGlobalChangeCallback(
	  fastdelegate::FastDelegate2< ConVar*, const char* > delegate,
	  ICvar* instance,
	  bool post = false )
	{
		return l_SMGlue_ICvar__CallGlobalChangeCallback.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_ICvar__CallGlobalChangeCallbacks(
	  fastdelegate::FastDelegate3< ConVar*, const char*, float > delegate,
	  ICvar* instance,
	  bool post = false )
	{
		return l_SMGlue_ICvar__CallGlobalChangeCallbacks.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_ICvar__RegisterConCommand( fastdelegate::FastDelegate1< ConCommandBase* > delegate,
														 ICvar* instance,
														 bool post = false )
	{
		return l_SMGlue_ICvar__RegisterConCommand.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_ICvar__UnregisterConCommand( fastdelegate::FastDelegate1< ConCommandBase* > delegate,
														   ICvar* instance,
														   bool post = false )
	{
		return l_SMGlue_ICvar__UnregisterConCommand.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IEngineSound__EmitSound( fastdelegate::FastDelegate15< IRecipientFilter*,
																					 int,
																					 int,
																					 const char*,
																					 float,
																					 soundlevel_t,
																					 int,
																					 int,
																					 int,
																					 Vector*,
																					 Vector*,
																					 CUtlVector< Vector >*,
																					 bool,
																					 float,
																					 int,
																					 void > delegate,
													   IEngineSound* instance,
													   bool post = false )
	{
		return l_SMGlue_IEngineSound__EmitSound.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IEngineSound__EmitSound2( fastdelegate::FastDelegate15< IRecipientFilter*,
																					  int,
																					  int,
																					  const char*,
																					  float,
																					  float,
																					  int,
																					  int,
																					  int,
																					  Vector*,
																					  Vector*,
																					  CUtlVector< Vector >*,
																					  bool,
																					  float,
																					  int > delegate,
														IEngineSound* instance,
														bool post = false )
	{
		return l_SMGlue_IEngineSound__EmitSound2.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IGameEventManager2__FireEvent(
	  fastdelegate::FastDelegate2< IGameEvent*, bool, bool > delegate,
	  IGameEventManager2* instance,
	  bool post = false )
	{
		return l_SMGlue_IGameEventManager2__FireEvent.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_INetChannel__ProcessPacket(
	  fastdelegate::FastDelegate2< struct netpacket_s*, bool > delegate,
	  INetChannel* instance,
	  bool post = false )
	{
		return l_SMGlue_INetChannel__ProcessPacket.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_INetChannel__SendFile(
	  fastdelegate::FastDelegate2< const char*, unsigned int, bool > delegate,
	  INetChannel* instance,
	  bool post = false )
	{
		return l_SMGlue_INetChannel__SendFile.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameClients__ClientCommand(
	  fastdelegate::FastDelegate2< edict_t*, CCommand* > delegate,
	  IServerGameClients* instance,
	  bool post = false )
	{
		return l_SMGlue_IServerGameClients__ClientCommand.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameClients__ClientCommandKeyValues(
	  fastdelegate::FastDelegate2< edict_t*, KeyValues* > delegate,
	  IServerGameClients* instance,
	  bool post = false )
	{
		return l_SMGlue_IServerGameClients__ClientCommandKeyValues.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameClients__ClientConnect(
	  fastdelegate::FastDelegate5< edict_t*, const char*, const char*, char*, int, bool > delegate,
	  IServerGameClients* instance,
	  bool post = false )
	{
		return l_SMGlue_IServerGameClients__ClientConnect.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameClients__ClientDisconnect( fastdelegate::FastDelegate1< edict_t* > delegate,
																	IServerGameClients* instance,
																	bool post = false )
	{
		return l_SMGlue_IServerGameClients__ClientDisconnect.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameClients__ClientPutInServer(
	  fastdelegate::FastDelegate2< edict_t*, const char* > delegate,
	  IServerGameClients* instance,
	  bool post = false )
	{
		return l_SMGlue_IServerGameClients__ClientPutInServer.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameClients__ClientSettingsChanged(
	  fastdelegate::FastDelegate1< edict_t* > delegate,
	  IServerGameClients* instance,
	  bool post = false )
	{
		return l_SMGlue_IServerGameClients__ClientSettingsChanged.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameClients__ClientVoice( fastdelegate::FastDelegate1< edict_t* > delegate,
															   IServerGameClients* instance,
															   bool post = false )
	{
		return l_SMGlue_IServerGameClients__ClientVoice.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameClients__SetCommandClient( fastdelegate::FastDelegate1< int > delegate,
																	IServerGameClients* instance,
																	bool post = false )
	{
		return l_SMGlue_IServerGameClients__SetCommandClient.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameDLL__GameFrame( fastdelegate::FastDelegate2< bool, bool > delegate,
														 IServerGameDLL* instance,
														 bool post = false )
	{
		return l_SMGlue_IServerGameDLL__GameFrame.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameDLL__GameServerSteamAPIActivated( fastdelegate::FastDelegate0<> delegate,
																		   IServerGameDLL* instance,
																		   bool post = false )
	{
		return l_SMGlue_IServerGameDLL__GameServerSteamAPIActivated.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameDLL__GetGameDescription( fastdelegate::FastDelegate0< const char* > delegate,
																  IServerGameDLL* instance,
																  bool post = false )
	{
		return l_SMGlue_IServerGameDLL__GetGameDescription.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameDLL__LevelInit(
	  fastdelegate::FastDelegate6< const char*, const char*, const char*, const char*, bool, bool, bool > delegate,
	  IServerGameDLL* instance,
	  bool post = false )
	{
		return l_SMGlue_IServerGameDLL__LevelInit.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameDLL__LevelShutdown( fastdelegate::FastDelegate0<> delegate,
															 IServerGameDLL* instance,
															 bool post = false )
	{
		return l_SMGlue_IServerGameDLL__LevelShutdown.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameDLL__OnQueryCvarValueFinished(
	  fastdelegate::FastDelegate5< QueryCvarCookie_t, edict_t*, EQueryCvarValueStatus, const char*, const char* >
		delegate,
	  IServerGameDLL* instance,
	  bool post = false )
	{
		return l_SMGlue_IServerGameDLL__OnQueryCvarValueFinished.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameDLL__ServerActivate( fastdelegate::FastDelegate3< edict_t*, int, int > delegate,
															  IServerGameDLL* instance,
															  bool post = false )
	{
		return l_SMGlue_IServerGameDLL__ServerActivate.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameDLL__ServerHibernationUpdate( fastdelegate::FastDelegate1< bool > delegate,
																	   IServerGameDLL* instance,
																	   bool post = false )
	{
		return l_SMGlue_IServerGameDLL__ServerHibernationUpdate.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameDLL__SetServerHibernation( fastdelegate::FastDelegate1< bool > delegate,
																	IServerGameDLL* instance,
																	bool post = false )
	{
		return l_SMGlue_IServerGameDLL__SetServerHibernation.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerGameDLL__Think( fastdelegate::FastDelegate1< bool > delegate,
													 IServerGameDLL* instance,
													 bool post = false )
	{
		return l_SMGlue_IServerGameDLL__Think.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerPluginCallbacks__OnQueryCvarValueFinished(
	  fastdelegate::FastDelegate5< QueryCvarCookie_t, edict_t*, EQueryCvarValueStatus, const char*, const char* >
		delegate,
	  IServerPluginCallbacks* instance,
	  bool post = false )
	{
		return l_SMGlue_IServerPluginCallbacks__OnQueryCvarValueFinished.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IServerPluginHelpers__CreateMessage(
	  fastdelegate::FastDelegate4< edict_t*, DIALOG_TYPE, KeyValues*, IServerPluginCallbacks* > delegate,
	  IServerPluginHelpers* instance,
	  bool post = false )
	{
		return l_SMGlue_IServerPluginHelpers__CreateMessage.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IVEngineServer__ChangeLevel(
	  fastdelegate::FastDelegate2< const char*, const char* > delegate,
	  IVEngineServer* instance,
	  bool post = false )
	{
		return l_SMGlue_IVEngineServer__ChangeLevel.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IVEngineServer__ClientCommand(
	  fastdelegate::FastDelegate2< edict_t*, const char* > delegate,
	  IVEngineServer* instance,
	  bool post = false )
	{
		return l_SMGlue_IVEngineServer__ClientCommand.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IVEngineServer__ClientPrintf(
	  fastdelegate::FastDelegate2< edict_t*, const char* > delegate,
	  IVEngineServer* instance,
	  bool post = false )
	{
		return l_SMGlue_IVEngineServer__ClientPrintf.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IVEngineServer__EmitAmbientSound(
	  fastdelegate::FastDelegate8< int, Vector*, const char*, float, soundlevel_t, int, int, float > delegate,
	  IVEngineServer* instance,
	  bool post = false )
	{
		return l_SMGlue_IVEngineServer__EmitAmbientSound.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IVEngineServer__GetMapEntitiesString( fastdelegate::FastDelegate0< const char* > delegate,
																	IVEngineServer* instance,
																	bool post = false )
	{
		return l_SMGlue_IVEngineServer__GetMapEntitiesString.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IVEngineServer__LogPrint( fastdelegate::FastDelegate1< const char* > delegate,
														IVEngineServer* instance,
														bool post = false )
	{
		return l_SMGlue_IVEngineServer__LogPrint.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IVEngineServer__MessageEnd( fastdelegate::FastDelegate0<> delegate,
														  IVEngineServer* instance,
														  bool post = false )
	{
		return l_SMGlue_IVEngineServer__MessageEnd.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IVEngineServer__PlaybackTempEntity(
	  fastdelegate::FastDelegate5< IRecipientFilter*, float, const void*, SendTable*, int > delegate,
	  IVEngineServer* instance,
	  bool post = false )
	{
		return l_SMGlue_IVEngineServer__PlaybackTempEntity.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IVEngineServer__UserMessageBegin(
	  fastdelegate::FastDelegate2< IRecipientFilter*, int, bf_write* > delegate,
	  IVEngineServer* instance,
	  bool post = false )
	{
		return l_SMGlue_IVEngineServer__UserMessageBegin.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_IVoiceServer__SetClientListening(
	  fastdelegate::FastDelegate3< int, int, bool, bool > delegate,
	  IVoiceServer* instance,
	  bool post = false )
	{
		return l_SMGlue_IVoiceServer__SetClientListening.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P0__CanBeAutobalanced( fastdelegate::FastDelegate0< bool > delegate,
													 CBaseEntity* instance,
													 bool post = false )
	{
		return l_SMGlue_P0__CanBeAutobalanced.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P0__GetMaxHealth( fastdelegate::FastDelegate0< int > delegate,
												CBaseEntity* instance,
												bool post = false )
	{
		return l_SMGlue_P0__GetMaxHealth.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P0__PostThink( fastdelegate::FastDelegate0< void > delegate,
											 CBaseEntity* instance,
											 bool post = false )
	{
		return l_SMGlue_P0__PostThink.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P0__PreThink( fastdelegate::FastDelegate0< void > delegate,
											CBaseEntity* instance,
											bool post = false )
	{
		return l_SMGlue_P0__PreThink.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P0__Reload( fastdelegate::FastDelegate0< bool > delegate,
										  CBaseEntity* instance,
										  bool post = false )
	{
		return l_SMGlue_P0__Reload.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P0__SGD_GameInit( fastdelegate::FastDelegate0< bool > delegate,
												IServerGameDLL* instance,
												bool post = false )
	{
		return l_SMGlue_P0__SGD_GameInit.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P0__Spawn( fastdelegate::FastDelegate0< void > delegate,
										 CBaseEntity* instance,
										 bool post = false )
	{
		return l_SMGlue_P0__Spawn.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P0__Think( fastdelegate::FastDelegate0< void > delegate,
										 CBaseEntity* instance,
										 bool post = false )
	{
		return l_SMGlue_P0__Think.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__Blocked( fastdelegate::FastDelegate1< CBaseEntity*, void > delegate,
										   CBaseEntity* instance,
										   bool post = false )
	{
		return l_SMGlue_P1__Blocked.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__EndTouch( fastdelegate::FastDelegate1< CBaseEntity*, void > delegate,
											CBaseEntity* instance,
											bool post = false )
	{
		return l_SMGlue_P1__EndTouch.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__FireBullets( fastdelegate::FastDelegate1< FireBulletsInfo_t*, int > delegate,
											   CBaseEntity* instance,
											   bool post = false )
	{
		return l_SMGlue_P1__FireBullets.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__GroundEntChanged( fastdelegate::FastDelegate1< void*, void > delegate,
													CBaseEntity* instance,
													bool post = false )
	{
		return l_SMGlue_P1__GroundEntChanged.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__OnTakeDamage( fastdelegate::FastDelegate1< CTakeDamageInfo*, int > delegate,
												CBaseEntity* instance,
												bool post = false )
	{
		return l_SMGlue_P1__OnTakeDamage.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__OnTakeDamage_Alive( fastdelegate::FastDelegate1< CTakeDamageInfo*, int > delegate,
													  CBaseEntity* instance,
													  bool post = false )
	{
		return l_SMGlue_P1__OnTakeDamage_Alive.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__StartTouch( fastdelegate::FastDelegate1< CBaseEntity*, void > delegate,
											  CBaseEntity* instance,
											  bool post = false )
	{
		return l_SMGlue_P1__StartTouch.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__Touch( fastdelegate::FastDelegate1< CBaseEntity*, void > delegate,
										 CBaseEntity* instance,
										 bool post = false )
	{
		return l_SMGlue_P1__Touch.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__VPhysicsUpdate( fastdelegate::FastDelegate1< IPhysicsObject*, void > delegate,
												  CBaseEntity* instance,
												  bool post = false )
	{
		return l_SMGlue_P1__VPhysicsUpdate.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__Weapon_CanSwitchTo( fastdelegate::FastDelegate1< CBaseCombatWeapon*, bool > delegate,
													  CBaseEntity* instance,
													  bool post = false )
	{
		return l_SMGlue_P1__Weapon_CanSwitchTo.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__Weapon_CanUse( fastdelegate::FastDelegate1< CBaseCombatWeapon*, bool > delegate,
												 CBaseEntity* instance,
												 bool post = false )
	{
		return l_SMGlue_P1__Weapon_CanUse.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P1__Weapon_Equip( fastdelegate::FastDelegate1< CBaseCombatWeapon*, void > delegate,
												CBaseEntity* instance,
												bool post = false )
	{
		return l_SMGlue_P1__Weapon_Equip.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P2__PlayerRunCmdHook(
	  fastdelegate::FastDelegate2< CUserCmd*, IMoveHelper*, void > delegate,
	  CBaseEntity* instance,
	  bool post = false )
	{
		return l_SMGlue_P2__PlayerRunCmdHook2.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P2__SetTransmit( fastdelegate::FastDelegate2< CCheckTransmitInfo*, bool, void > delegate,
											   CBaseEntity* instance,
											   bool post = false )
	{
		return l_SMGlue_P2__SetTransmit.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P2__ShouldCollide( fastdelegate::FastDelegate2< int, int, bool > delegate,
												 CBaseEntity* instance,
												 bool post = false )
	{
		return l_SMGlue_P2__ShouldCollide.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P2__Weapon_Switch( fastdelegate::FastDelegate2< CBaseCombatWeapon*, int, bool > delegate,
												 CBaseEntity* instance,
												 bool post = false )
	{
		return l_SMGlue_P2__Weapon_Switch.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P3__TraceAttack(
	  fastdelegate::FastDelegate3< CTakeDamageInfo*, Vector*, CGameTrace*, void > delegate,
	  CBaseEntity* instance,
	  bool post = false )
	{
		return l_SMGlue_P3__TraceAttack.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P3__Weapon_Drop(
	  fastdelegate::FastDelegate3< CBaseCombatWeapon*, const Vector*, const Vector*, void > delegate,
	  CBaseEntity* instance,
	  bool post = false )
	{
		return l_SMGlue_P3__Weapon_Drop.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P4__TraceAttack(
	  fastdelegate::FastDelegate4< CTakeDamageInfo*, Vector*, CGameTrace*, CDmgAccumulator*, void > delegate,
	  CBaseEntity* instance,
	  bool post = false )
	{
		return l_SMGlue_P4__TraceAttack.add( delegate, instance, post ? 1 : 0 );
	}

	inline int SMGlue_MkHook4_P4__Use(
	  fastdelegate::FastDelegate4< CBaseEntity*, CBaseEntity*, USE_TYPE, float, void > delegate,
	  CBaseEntity* instance,
	  bool post = false )
	{
		return l_SMGlue_P4__Use.add( delegate, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_ConCommand__Dispatch( int hk, ConCommand* instance, bool post = false )
	{
		l_SMGlue_ConCommand__Dispatch.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IBaseFileSystem__FileExists( int hk, IBaseFileSystem* instance, bool post = false )
	{
		l_SMGlue_IBaseFileSystem__FileExists.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IClientMessageHandler__ProcessVoiceData( int hk,
																		IClientMessageHandler* instance,
																		bool post = false )
	{
		l_SMGlue_IClientMessageHandler__ProcessVoiceData.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_ICvar__CallGlobalChangeCallback( int hk, ICvar* instance, bool post = false )
	{
		l_SMGlue_ICvar__CallGlobalChangeCallback.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_ICvar__CallGlobalChangeCallbacks( int hk, ICvar* instance, bool post = false )
	{
		l_SMGlue_ICvar__CallGlobalChangeCallbacks.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_ICvar__RegisterConCommand( int hk, ICvar* instance, bool post = false )
	{
		l_SMGlue_ICvar__RegisterConCommand.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_ICvar__UnregisterConCommand( int hk, ICvar* instance, bool post = false )
	{
		l_SMGlue_ICvar__UnregisterConCommand.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IEngineSound__EmitSound( int hk, IEngineSound* instance, bool post = false )
	{
		l_SMGlue_IEngineSound__EmitSound.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IEngineSound__EmitSound2( int hk, IEngineSound* instance, bool post = false )
	{
		l_SMGlue_IEngineSound__EmitSound2.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IGameEventManager2__FireEvent( int hk, IGameEventManager2* instance, bool post = false )
	{
		l_SMGlue_IGameEventManager2__FireEvent.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_INetChannel__ProcessPacket( int hk, INetChannel* instance, bool post = false )
	{
		l_SMGlue_INetChannel__ProcessPacket.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_INetChannel__SendFile( int hk, INetChannel* instance, bool post = false )
	{
		l_SMGlue_INetChannel__SendFile.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameClients__ClientCommand( int hk,
																  IServerGameClients* instance,
																  bool post = false )
	{
		l_SMGlue_IServerGameClients__ClientCommand.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameClients__ClientCommandKeyValues( int hk,
																		   IServerGameClients* instance,
																		   bool post = false )
	{
		l_SMGlue_IServerGameClients__ClientCommandKeyValues.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameClients__ClientConnect( int hk,
																  IServerGameClients* instance,
																  bool post = false )
	{
		l_SMGlue_IServerGameClients__ClientConnect.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameClients__ClientDisconnect( int hk,
																	 IServerGameClients* instance,
																	 bool post = false )
	{
		l_SMGlue_IServerGameClients__ClientDisconnect.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameClients__ClientPutInServer( int hk,
																	  IServerGameClients* instance,
																	  bool post = false )
	{
		l_SMGlue_IServerGameClients__ClientPutInServer.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameClients__ClientSettingsChanged( int hk,
																		  IServerGameClients* instance,
																		  bool post = false )
	{
		l_SMGlue_IServerGameClients__ClientSettingsChanged.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameClients__ClientVoice( int hk,
																IServerGameClients* instance,
																bool post = false )
	{
		l_SMGlue_IServerGameClients__ClientVoice.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameClients__SetCommandClient( int hk,
																	 IServerGameClients* instance,
																	 bool post = false )
	{
		l_SMGlue_IServerGameClients__SetCommandClient.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameDLL__GameFrame( int hk, IServerGameDLL* instance, bool post = false )
	{
		l_SMGlue_IServerGameDLL__GameFrame.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameDLL__GameServerSteamAPIActivated( int hk,
																			IServerGameDLL* instance,
																			bool post = false )
	{
		l_SMGlue_IServerGameDLL__GameServerSteamAPIActivated.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameDLL__GetGameDescription( int hk, IServerGameDLL* instance, bool post = false )
	{
		l_SMGlue_IServerGameDLL__GetGameDescription.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameDLL__LevelInit( int hk, IServerGameDLL* instance, bool post = false )
	{
		l_SMGlue_IServerGameDLL__LevelInit.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameDLL__LevelShutdown( int hk, IServerGameDLL* instance, bool post = false )
	{
		l_SMGlue_IServerGameDLL__LevelShutdown.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameDLL__OnQueryCvarValueFinished( int hk,
																		 IServerGameDLL* instance,
																		 bool post = false )
	{
		l_SMGlue_IServerGameDLL__OnQueryCvarValueFinished.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameDLL__ServerActivate( int hk, IServerGameDLL* instance, bool post = false )
	{
		l_SMGlue_IServerGameDLL__ServerActivate.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameDLL__ServerHibernationUpdate( int hk,
																		IServerGameDLL* instance,
																		bool post = false )
	{
		l_SMGlue_IServerGameDLL__ServerHibernationUpdate.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameDLL__SetServerHibernation( int hk,
																	 IServerGameDLL* instance,
																	 bool post = false )
	{
		l_SMGlue_IServerGameDLL__SetServerHibernation.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerGameDLL__Think( int hk, IServerGameDLL* instance, bool post = false )
	{
		l_SMGlue_IServerGameDLL__Think.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerPluginCallbacks__OnQueryCvarValueFinished( int hk,
																				 IServerPluginCallbacks* instance,
																				 bool post = false )
	{
		l_SMGlue_IServerPluginCallbacks__OnQueryCvarValueFinished.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IServerPluginHelpers__CreateMessage( int hk,
																	IServerPluginHelpers* instance,
																	bool post = false )
	{
		l_SMGlue_IServerPluginHelpers__CreateMessage.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IVEngineServer__ChangeLevel( int hk, IVEngineServer* instance, bool post = false )
	{
		l_SMGlue_IVEngineServer__ChangeLevel.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IVEngineServer__ClientCommand( int hk, IVEngineServer* instance, bool post = false )
	{
		l_SMGlue_IVEngineServer__ClientCommand.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IVEngineServer__ClientPrintf( int hk, IVEngineServer* instance, bool post = false )
	{
		l_SMGlue_IVEngineServer__ClientPrintf.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IVEngineServer__EmitAmbientSound( int hk, IVEngineServer* instance, bool post = false )
	{
		l_SMGlue_IVEngineServer__EmitAmbientSound.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IVEngineServer__GetMapEntitiesString( int hk,
																	 IVEngineServer* instance,
																	 bool post = false )
	{
		l_SMGlue_IVEngineServer__GetMapEntitiesString.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IVEngineServer__LogPrint( int hk, IVEngineServer* instance, bool post = false )
	{
		l_SMGlue_IVEngineServer__LogPrint.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IVEngineServer__MessageEnd( int hk, IVEngineServer* instance, bool post = false )
	{
		l_SMGlue_IVEngineServer__MessageEnd.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IVEngineServer__PlaybackTempEntity( int hk, IVEngineServer* instance, bool post = false )
	{
		l_SMGlue_IVEngineServer__PlaybackTempEntity.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IVEngineServer__UserMessageBegin( int hk, IVEngineServer* instance, bool post = false )
	{
		l_SMGlue_IVEngineServer__UserMessageBegin.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_IVoiceServer__SetClientListening( int hk, IVoiceServer* instance, bool post = false )
	{
		l_SMGlue_IVoiceServer__SetClientListening.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P0__CanBeAutobalanced( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P0__CanBeAutobalanced.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P0__GetMaxHealth( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P0__GetMaxHealth.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P0__PostThink( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P0__PostThink.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P0__PreThink( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P0__PreThink.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P0__Reload( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P0__Reload.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P0__SGD_GameInit( int hk, IServerGameDLL* instance, bool post = false )
	{
		l_SMGlue_P0__SGD_GameInit.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P0__Spawn( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P0__Spawn.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P0__Think( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P0__Think.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__Blocked( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__Blocked.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__EndTouch( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__EndTouch.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__FireBullets( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__FireBullets.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__GroundEntChanged( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__GroundEntChanged.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__OnTakeDamage( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__OnTakeDamage.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__OnTakeDamage_Alive( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__OnTakeDamage_Alive.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__StartTouch( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__StartTouch.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__Touch( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__Touch.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__VPhysicsUpdate( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__VPhysicsUpdate.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__Weapon_CanSwitchTo( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__Weapon_CanSwitchTo.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__Weapon_CanUse( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__Weapon_CanUse.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P1__Weapon_Equip( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P1__Weapon_Equip.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P2__PlayerRunCmdHook( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P2__PlayerRunCmdHook2.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P2__SetTransmit( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P2__SetTransmit.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P2__ShouldCollide( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P2__ShouldCollide.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P2__Weapon_Switch( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P2__Weapon_Switch.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P3__TraceAttack( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P3__TraceAttack.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P3__Weapon_Drop( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P3__Weapon_Drop.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P4__TraceAttack( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P4__TraceAttack.remove( hk, instance, post ? 1 : 0 );
	}

	inline void SMGlue_RmHook4_P4__Use( int hk, CBaseEntity* instance, bool post = false )
	{
		l_SMGlue_P4__Use.remove( hk, instance, post ? 1 : 0 );
	}
};

#endif // !CSOURCEMOD_GLUE_H_