
#include "glue.hpp"

SourcemodRouter< fastdelegate::FastDelegate4<CBaseEntityOutput*,CBaseEntity*, CBaseEntity*, float>, CBaseEntityOutput > g_SMGlue_COutputEvent__FireOutput;
SourcemodRouter< fastdelegate::FastDelegate1<CCSWeaponInfo*, int>, CCSWeaponInfo > g_SMGlue_CCSWeaponInfo__GetWeaponPrice;
SourcemodRouter< fastdelegate::FastDelegate2<CCSPlayer*,const char*, int>, CCSPlayer > g_SMGlue_CCSPlayer__HandleCommand_Buy_Internal;
SourcemodRouter< fastdelegate::FastDelegate3<CCSGameRules*, float, int>, CCSGameRules > g_SMGlue_CCSGameRules__TerminateRound;
SourcemodRouter< fastdelegate::FastDelegate4<CCSPlayer*,CBaseCombatWeapon*,bool,bool,bool>, CCSPlayer > g_SMGlue_CCSPlayer__CSWeaponDrop;