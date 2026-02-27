import re

def update_cpp_includes(file_path, include_mapping):
    # Read the original C++ file content
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read()

    # Regex to match #include <header.h> or #include "header.h"
    # Group 1 captures the full header path
    pattern = r'#include\s*[<"]([^>"]+)[>"]'

    def replacement_func(match):
        original_include = match.group(1)
        # Check if this include needs to be updated
        if original_include in include_mapping:
            new_include = include_mapping[original_include]
            # Use quotes or brackets based on your project preference
            return f'#include "{new_include}"'
        return match.group(0)  # No change

    # Apply the replacements
    new_content = re.sub(pattern, replacement_func, content)

    # Save the modified content back to the file
    with open(file_path, 'w', encoding='utf-8') as file:
        file.write(new_content)

if __name__ == '__main__':

    FILES = {
        'AutoHandleRooter.h': 'sourcemod/AutoHandleRooter.h', 
        'CDetour/detourhelpers.h': 'sourcemod/CDetour/detourhelpers.h', 
        'CDetour/detours.h': 'sourcemod/CDetour/detours.h', 
        'IADTFactory.h': 'sourcemod/IADTFactory.h', 
        'IAdminSystem.h': 'sourcemod/IAdminSystem.h', 
        'ICellArray.h': 'sourcemod/ICellArray.h', 
        'IDBDriver.h': 'sourcemod/IDBDriver.h', 
        'IExtensionSys.h': 'sourcemod/IExtensionSys.h', 
        'IForwardSys.h': 'sourcemod/IForwardSys.h', 
        'IGameConfigs.h': 'sourcemod/IGameConfigs.h', 
        'IGameHelpers.h': 'sourcemod/IGameHelpers.h', 
        'IHandleSys.h': 'sourcemod/IHandleSys.h', 
        'ILibrarySys.h': 'sourcemod/ILibrarySys.h', 
        'IMemoryUtils.h': 'sourcemod/IMemoryUtils.h', 
        'IMenuManager.h': 'sourcemod/IMenuManager.h', 
        'IPlayerHelpers.h': 'sourcemod/IPlayerHelpers.h', 
        'IPluginSys.h': 'sourcemod/IPluginSys.h', 
        'IRootConsoleMenu.h': 'sourcemod/IRootConsoleMenu.h', 
        'IShareSys.h': 'sourcemod/IShareSys.h', 
        'ISourceMod.h': 'sourcemod/ISourceMod.h', 
        'ITextParsers.h': 'sourcemod/ITextParsers.h', 
        'IThreader.h': 'sourcemod/IThreader.h', 
        'ITimerSystem.h': 'sourcemod/ITimerSystem.h', 
        'ITranslator.h': 'sourcemod/ITranslator.h', 
        'IUserMessages.h': 'sourcemod/IUserMessages.h', 
        'ReentrantList.h': 'sourcemod/ReentrantList.h', 
        'compat_wrappers.h': 'sourcemod/compat_wrappers.h', 
        'extensions/IBinTools.h': 'sourcemod/extensions/IBinTools.h', 
        'extensions/ISDKHooks.h': 'sourcemod/extensions/ISDKHooks.h', 
        'extensions/ISDKTools.h': 'sourcemod/extensions/ISDKTools.h', 
        'extensions/ITopMenus.h': 'sourcemod/extensions/ITopMenus.h', 
        'extensions/IWebternet.h': 'sourcemod/extensions/IWebternet.h', 
        'jit/jit_helpers.h': 'sourcemod/jit/jit_helpers.h', 
        'metamod_wrappers.h': 'sourcemod/metamod_wrappers.h', 
        'mms_sample_ext/sm_ext.h': 'sourcemod/mms_sample_ext/sm_ext.h', 
        'mms_sample_ext/sm_sdk_config.h': 'sourcemod/mms_sample_ext/sm_sdk_config.h', 
        'mms_sample_ext/stub_mm.h': 'sourcemod/mms_sample_ext/stub_mm.h', 
        'mms_sample_ext/stub_util.h': 'sourcemod/mms_sample_ext/stub_util.h', 
        'sample_ext/extension.h': 'sourcemod/sample_ext/extension.h', 
        'sample_ext/smsdk_config.h': 'sourcemod/sample_ext/smsdk_config.h', 
        'sample_ext_nosdk/extension.h': 'sourcemod/sample_ext_nosdk/extension.h', 
        'sample_ext_nosdk/smsdk_config.h': 'sourcemod/sample_ext_nosdk/smsdk_config.h', 
        'sm_argbuffer.h': 'sourcemod/sm_argbuffer.h', 
        'sm_hashmap.h': 'sourcemod/sm_hashmap.h', 
        'sm_invalidparamhandler.h': 'sourcemod/sm_invalidparamhandler.h', 
        'sm_memtable.h': 'sourcemod/sm_memtable.h', 
        'sm_namehashset.h': 'sourcemod/sm_namehashset.h', 
        'sm_platform.h': 'sourcemod/sm_platform.h', 
        'sm_queue.h': 'sourcemod/sm_queue.h', 
        'sm_trie_tpl.h': 'sourcemod/sm_trie_tpl.h', 
        'smsdk_ext.h': 'sourcemod/smsdk_ext.h', 
        'sourcemod_version.h': 'sourcemod/sourcemod_version.h', 
        'vtable_hook_helper.h': 'sourcemod/vtable_hook_helper.h'
    }

    FILES_TO_UPDATE = ['AutoHandleRooter.h', 'CDetour/detourhelpers.h', 'CDetour/detours.cpp', 'CDetour/detours.h', 'IADTFactory.h', 'IAdminSystem.h', 'ICellArray.h', 'IDBDriver.h', 'IExtensionSys.h', 'IForwardSys.h', 'IGameConfigs.h', 'IGameHelpers.h', 'IHandleSys.h', 'ILibrarySys.h', 'IMemoryUtils.h', 'IMenuManager.h', 'IPlayerHelpers.h', 'IPluginSys.h', 'IRootConsoleMenu.h', 'IShareSys.h', 'ISourceMod.h', 'ITextParsers.h', 'IThreader.h', 'ITimerSystem.h', 'ITranslator.h', 'IUserMessages.h', 'ReentrantList.h', 'compat_wrappers.h', 'extensions/IBinTools.h', 'extensions/ISDKHooks.h', 'extensions/ISDKTools.h', 'extensions/ITopMenus.h', 'extensions/IWebternet.h', 'jit/jit_helpers.h', 'metamod_wrappers.h', 'mms_sample_ext/sm_ext.cpp', 'mms_sample_ext/sm_ext.h', 'mms_sample_ext/sm_sdk_config.cpp', 'mms_sample_ext/sm_sdk_config.h', 'mms_sample_ext/stub_mm.cpp', 'mms_sample_ext/stub_mm.h', 'mms_sample_ext/stub_util.cpp', 'mms_sample_ext/stub_util.h', 'sample_ext/extension.cpp', 'sample_ext/extension.h', 'sample_ext/smsdk_config.h', 'sample_ext_nosdk/extension.cpp', 'sample_ext_nosdk/extension.h', 'sample_ext_nosdk/smsdk_config.h', 'sm_argbuffer.h', 'sm_hashmap.h', 'sm_invalidparamhandler.h', 'sm_memtable.h', 'sm_namehashset.h', 'sm_platform.h', 'sm_queue.h', 'sm_trie_tpl.h', 'smsdk_ext.cpp', 'smsdk_ext.h', 'sourcemod_version.h', 'vtable_hook_helper.h']

    for file in FILES_TO_UPDATE:
        update_cpp_includes(file, FILES)

    # print(list(sorted(filter(lambda x : x.endswith(".h") or x.endswith(".hpp") or x.endswith("cpp") or x.endswith(".c"), glob.glob("**/*") + glob.glob("*")))))
    # paste 
    # VIM update mapping
    # cwd in target dir
    # run
