import re

FILE = 'source_sh_add_hook_COREONLY.txt'
FILE2 = 'sourcemod_sh_decl_hook.txt'
FILE3 = 'source_sh_decl_manual.txt'

# ADD HOOOK
sh_add_hook = []
with open(FILE) as fd:
    data = fd.read()

    current_file = None
    results = {}

    for line in data.splitlines():
        line = line.strip()
        if not line:
            continue
            
        # Check if line is a file path (starts with /)
        if line.startswith('/'):
            current_file = line
            results[current_file] = []
        
        # Check if line contains the hook
        elif "SH_ADD_HOOK" in line and current_file:
            # Optional: Use regex to extract just the arguments inside SH_ADD_HOOK(...)
            match = re.search(r'SH_ADD_HOOK\((.*?)\)', line)
            if match:
                hook_content = match.group(1)
                results[current_file].append(hook_content)

    # Display Results
    for file, hooks in results.items():
        sh_add_hook.append((file,hooks))

# DECL HOOK
sh_decl_hook = []
with open(FILE2) as fd:
    # Regex breakdown:
    # (/[^\s]+)               -> Matches the file path (starts with / until first space/newline)
    # ([\s\S]+?)              -> Non-greedy match for everything until the next path or end
    # SH_DECL_HOOK(\d+)(_void)? -> Matches the macro, capturing hook 'N' and optional '_void'
    # \((.*?)\);              -> Captures everything inside the parentheses until the semicolon
    sh_decl_hook = []
    file_blocks = re.findall(r'(/[^\s]+)([\s\S]+?)(?=(?:/\w|$))', fd.read())

    for path, content in file_blocks:
        hooks = re.findall(r'SH_DECL_HOOK(\d+)(_void)?\((.*?)\);', content)
        for hook_n, is_void, params in hooks:
            sh_decl_hook.append((path, hook_n, is_void, params))

# DECL MAN HOOK
sh_decl_mhk = []
with open(FILE3) as fd:
    file_blocks = re.findall(r'(/[^\s]+)([\s\S]+?)(?=(?:/\w|$))', fd.read())
    for path, content in file_blocks:
        hooks = re.findall(r'SH_DECL_MANUALHOOK(\d+)(_void)?\((.*?)\);', content)
        for hook_n, is_void, params in hooks:
            sh_decl_mhk.append((path, hook_n, is_void, params))

# HOOK GENERATOR
# TODO: store like 
hooks = []
MEMBER_FILTER = ["RegisterConCommandBase", "SendUserMessage"]

for declaration in sh_decl_hook:

    break
    def unpack_parameters(params: str):
        return tuple(map(lambda x : x.strip(), params.split(",")))

    decl_file = declaration[0]
    decl_num_args = int(declaration[1])
    decl_is_void = 'void' in declaration[2]
    decl_params = unpack_parameters(declaration[3])
    decl_class = decl_params[0]
    decl_member = decl_params[1]
    decl_attr = decl_params[2]
    decl_overload = decl_params[3]
    decl_arg_types = decl_params[4:]

    if decl_member in MEMBER_FILTER:
        continue

    qn = f'{decl_class}::{decl_member}'
    if qn in hooks:
        continue

    for add_file, add_hooks in sh_add_hook:
        for add_hook in add_hooks:
            add_params = unpack_parameters(add_hook)
            add_class = add_params[0].replace('*', '')
            add_member = add_params[1]

            add_attr = add_params[2]
            add_overload = add_params[3]

            if add_file == decl_file and add_class == decl_class and add_member == decl_member:
                hooks.append(qn)

                fast_delegate_args = decl_arg_types[-decl_num_args:] if decl_is_void else decl_arg_types[-decl_num_args - 1:-1]
                fast_delegate_return_sep =  ', ' if len(fast_delegate_args) > 0 else '' 
                fast_delegate_return_type = '' if decl_is_void else f'{fast_delegate_return_sep}{decl_arg_types[-1]}'
                fast_delegate_type = f"fastdelegate::FastDelegate{decl_num_args}<{', '.join(fast_delegate_args)}{fast_delegate_return_type}>"
                hook_instance_type = f"{add_params[0]} *"
                router_name = f"g_SMGlue_{add_class}__{add_member}"

                print(f"// {add_class}::{add_member} #####################################################")
                print(f"// FILE {add_file}")
                print(f"// SH_DECL_HOOK {declaration[1:]}")
                print(f"// SH_ADD_HOOK {add_hook}")
                print(f"// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
                print(f"extern SourcemodRouter<{fast_delegate_type}, {add_class}> {router_name};")
                print(f"int SMGlue_MkHook4_{add_class}__{add_member} ( {fast_delegate_type} delegate , {hook_instance_type} instance, bool post = false ) {{return {router_name}.add(delegate,instance, post ? 1 : 0);}}")
                print(f"void SMGlue_RmHook4_{add_class}__{add_member} ( int hk, {hook_instance_type} instance, bool post = false ) {{{router_name}.remove(hk, instance, post ? 1 : 0);}}")
                print(f"// ===============================================================================================")
                print(f'// #include "glue.hpp"')
                print(f'// ...')
                print(f"// int router = 0, route = 0;")
                print(f"// {fast_delegate_type} delegate;")
                print(f"// while ( {router_name}.loop(router,route,&delegate) ) {{ delegate( {', '.join(map(lambda x : f'a{x}', range(1, 1 + len(fast_delegate_args))))} ); }} ")
                print(f"//")
                print(f"// -----------------------------------------------------------------------------------------------")
                # if(add_member == "GetMapEntitiesString"):
                    # breakpoint()
                break

for manual_declaration in sh_decl_mhk:
    argc = int(manual_declaration[1])
    is_void = 'void' in manual_declaration[2]
    args = list(map(lambda x : x.strip(), manual_declaration[-1].split(',')))
    name = args[0]
    param = args[4:] if is_void else args[5:]
    rettype = 'void' if is_void else args[4]

    fast_delegate_args = param
    fast_delegate_return_type = ', ' + rettype if len(param) > 0 else rettype
    fast_delegate_type = f"fastdelegate::FastDelegate{argc}<{', '.join(fast_delegate_args)}{fast_delegate_return_type}>"
    hook_instance_type = f"TClass *"
    router_name = f"g_SMGlue_P{argc}__{name}"

    print(f'// {manual_declaration[0]}')
    print(f"extern SourcemodRouter<{fast_delegate_type}, TClass> {router_name};")
    print(f"int SMGlue_MkHook4_P{argc}__{name} ( {fast_delegate_type} delegate , {hook_instance_type} instance, bool post = false ) {{return {router_name}.add(delegate,instance, post ? 1 : 0);}}")
    print(f"void SMGlue_RmHook4_P{argc}__{name} ( int hk, {hook_instance_type} instance, bool post = false ) {{{router_name}.remove(hk, instance, post ? 1 : 0);}}")

for i in range(20):
    break
    #   50,1: SH_DECL_HOOK1_void(ICvar, RegisterConCommandBase, SH_NOATTRIB, 0, ConCommandBase *);
    #   42,1: SH_DECL_HOOK17(IEngineSound, EmitSound, SH_NOATTRIB, 1, int, IRecipientFilter &, int, int, const char *, unsigned int, const char *, float, soundlevel_t, int, int, int, const Vector *, const Vector *, CUtlVector<Vector> *, bool, float, int);
    args = ', '.join(map(lambda x : 'a' + str(x), range(i)))
    args_w_rettype = ', '.join(map(lambda x : f'a{x}', list(range(i)) + ['rettype']))
    print(f'#define SH_DECL_HOOK{i}_void(iface, member, unused, unused2, {args}) int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);')
    print(f'#define SH_DECL_HOOK{i}(iface, member, unused, unused2, {args_w_rettype}) int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);')

    print(f'#define SH_DECL_HOOK{i}_void(iface, member, unused, unused2, {args}) int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);')
    print(f'#define SH_DECL_HOOK{i}(iface, member, unused, unused2, {args_w_rettype}) int PRE_MEMBER(iface, member), POST_MEMBER(iface, member);')

for i in range(20):
    print(f'#define SH_DECL_MANUALHOOK{i}(...)')
    print(f'#define SH_DECL_MANUALHOOK{i}_void(...)')