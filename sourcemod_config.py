# includes are relative to each respective project directory

BASIC = {
    'defines': [],
    'keyValueDefines': {},
    'includes': [],
    'libraries': []
}

DEFAULT = {
    "defines": [
        'GAME_DLL',
        'SMEXT_CONF_METAMOD',
        'SMEXT_ENABLE_ADMINSYS',
		'SMEXT_ENABLE_ADTFACTORY',
		'SMEXT_ENABLE_DBMANAGER',
		'SMEXT_ENABLE_FORWARDSYS',
		'SMEXT_ENABLE_GAMECONF',
		'SMEXT_ENABLE_GAMEHELPERS',
		'SMEXT_ENABLE_HANDLESYS',
		'SMEXT_ENABLE_LIBSYS',
		'SMEXT_ENABLE_MEMUTILS',
		'SMEXT_ENABLE_MENUS',
		'SMEXT_ENABLE_PLAYERHELPERS',
		'SMEXT_ENABLE_PLUGINSYS',
		'SMEXT_ENABLE_ROOTCONSOLEMENU',
		'SMEXT_ENABLE_TEXTPARSERS',
		'SMEXT_ENABLE_THREADER',
		'SMEXT_ENABLE_TIMERSYS',
		'SMEXT_ENABLE_TRANSLATOR',
		'SMEXT_ENABLE_USERMSGS',
		'_GNU_SOURCE',
    ],
    "keyValueDefines": {
		'SE_EPISODEONE': '1',
		'SE_CS2': '25',
		'SE_DARKMESSIAH': '2',
		'SE_HL2DM': '7',
		'SE_PORTAL2': '18',
		'SE_TF2': '12',
		'SE_ORANGEBOX': '3',
		'SE_BLOODYGOODTIME': '4',
		'SE_LEFT4DEAD': '13',
		'SE_LEFT4DEAD2': '16',
		'SE_EYE': '5',
		'SE_CSS': '6',
		'SOURCE_ENGINE': '6',
		'SE_DODS': '8',
		'SE_PVKII': '10',
		'SE_BMS': '11',
		'SE_NUCLEARDAWN': '14',
		'SE_CONTAGION': '15',
		'SE_ALIENSWARM': '17',
		'SE_BLADE': '19',
		'SE_INSURGENCY': '20',
		'SE_DOI': '21',
		'SE_MCV': '22',
		'SE_CSGO': '23',
		'SE_DOTA': '24',
		'SE_MOCK': '26',
		'SE_DEADLOCK': '27',
		'SOURCE_ENGINE_PVKII': '27',
		'SE_SDK2013': '9',
		'V_snprintf': '_snprintf',
    },
    "includes": [
		'.',
		'..',
		'../game/shared',
		'../public',
		'../public/engine',
		'../public/game/server',
		'../public/mathlib',
		'../public/sourcemod',
		'../public/sourcemod/amtl',
		'../public/sourcemod/amtl/amtl',
		'../public/sourcemod/amtl/include',
		'../public/sourcemod/extensions',
		'../public/sourcemod/safetyhook',
		'../public/sourcemod/safetyhook/include',
		'../public/steam',
		'../public/tier0',
		'../public/tier1',
		'../sourcemod_base',
		'../sourcemod_bridge',
		'../sourcemod_metamod_core',
		'../sourcemod_metamod_core/sourcehook',
		'../sourcemod_sourcepawn/include',
        '../sourcemodglue'
    ],
    "libraries": ['tier0','tier2','tier3', 'mathlib'],
}

CONFIG = {
    "global": DEFAULT,
    "perProject": {
        'sourcemodcore': {
            **BASIC,
            'libraries': ['sourcemod_logic', 'sourcemodglue', 'tier1', 'vstdlib']
        },
        'sourcemodcstrike': {
            **BASIC,
            'libraries': ['sourcemod_core', 'sourcemodglue', 'tier1', 'vstdlib']
        },
        'sourcemodlogic': {
            **BASIC,
            'defines': ['SM_LOGIC'],
            'includes': ['../sourcemod_core'],
            'libraries': ['sourcemod_core', 'sourcemodglue', 'tier1', 'vstdlib']
        },
        'sourcemodcurl': {
            **BASIC,
            'defines': ['HOOKING_ENABLED', 'HAVE_STRING_H', 'HAVE_STDINT_H'],
            'libraries': ['sourcemod_curl_dep']
        },
        'sourcemoddhooks': {
            **BASIC,
            'defines': [],
            'includes': ['DynamicHooks', 'DynamicHooks/conventions'],
            'libraries': ['sourcemod_core', 'sourcemodglue', 'tier1', 'vstdlib']
            # not used
        },
        'sourcemodsdktools': {
            **BASIC,
			'includes': ['../game/server'],
            'defines': ['HOOKING_ENABLED', 'HAVE_STRING_H', 'HAVE_STDINT_H'],
            'libraries': ['sourcemod_core', 'sourcemodglue', 'tier1', 'vstdlib']
        },
        'sourcemodsdkhooks': {
            **BASIC,
            'includes': ['../game/server', '../game/shared/cstrike'],
            'defines': [],
            'libraries': ['sourcemod_core', 'sourcemodglue', 'tier1', 'vstdlib']
        },
        'sourcemodclientprefs': {
            **BASIC,
            'defines': [],
            'libraries': ['sourcemod_core', 'sourcemodglue', 'tier1', 'vstdlib']
        },
        'sourcemodregex': {
            **BASIC,
            'defines': [],
            'libraries': ['sourcemod_core', 'sourcemodglue', 'tier1', 'vstdlib']
        },
        'sourcemodtopmenus': {
            **BASIC,
            'libraries': ['sourcemodglue', 'tier1', 'vstdlib']
        },
        'sourcemodsqlite': {
            **BASIC,
            'libraries': ['sourcemodglue']
        },
        'sourcemodstructs': {
            **BASIC,
            'libraries': ['sourcemodglue', 'tier1', 'vstdlib']
        },
        'sourcemodgeoip': {
            **BASIC,
            'libraries': ['sourcemodglue']
        },
        'sourcemodmetamodcore': {
            **BASIC,
            'includes': ['../sourcemod_metamod_versionlib', '../sourcemod_metamod_loader'],
            'libraries': ['sourcemod_metamod_versionlib', 'sourcemodglue', 'tier1', 'vstdlib']
        },
        'sourcemodmetamodloader': {
            **BASIC,
            'includes': ['../public/metamod', '../sourcemod_metamod_core/sourcehook'],
            'keyValueDefines': {
                 'LIB_PREFIX': 'lib',
                 'LIB_SUFFIX': '.so'
            },
            'libraries': ['sourcemod_metamod_versionlib']
        },
        'sourcemodmetamodversionlib': {
            **BASIC,
            'includes': ['../public/metamod'],
        },
        'sourcemodsourcepawnvm': {
            **BASIC,
            'libraries': ['zlib', 'ZLIB']
        },
        'sourcemodbintools': {
             **BASIC,
            'includes': ['../public/sourcemod/jit', '../public/sourcemod/jit/x86'],
            'libraries': ['sourcemodglue', 'tier1', 'vstdlib']
        },
        'sourcemodsqlite1': {
             **BASIC,
        },
        'sourcemodglue': {
             **BASIC,
             'defines': ['GLUE_LOCAL']
        },
    },
}

def on_build(bld,proj):
	pass
def on_config(cfg,proj):
	pass

def build_vars(bld, includes: list, defines: list, libraries: list, project: str, windows: bool = False):
    def extract_vars(includes: list, defines: list, libraries: list, project, scope):
        config = scope[project] # dont handle errors!
        macros = defines + list(map(lambda x : '='.join(x),config['keyValueDefines'].items()))
        defines.extend(config['defines'])
        defines.extend(macros)
        includes.extend(config['includes'])
        libraries.extend(config['libraries'])
    extract_vars(includes, defines, libraries, 'global', CONFIG)
    extract_vars(includes, defines, libraries, project, CONFIG['perProject'])
    on_build(bld,project)

def configure_vars(conf, project: str,windows: bool = False):
    def extract_macros(defines: list, keyValueDefines: dict, project, scope):
        config = scope[project]
        defines.extend(config['defines'])
        keyValueDefines.update(config['keyValueDefines'])
    defines, keyValueDefines = [], {}
    extract_macros(defines,keyValueDefines,'global',CONFIG)
    extract_macros(defines,keyValueDefines,project,CONFIG['perProject'])
    if windows:
        for define in defines:
            conf.define(define)
        for key, val in keyValueDefines.items():
            conf.define(key, val)
    else:
        macros = defines + list(map(lambda x : '='.join(x),keyValueDefines.items()))
        conf.env.append_unique('DEFINES',macros)
    on_config(conf,project)
