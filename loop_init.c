#include <stdio.h>
#include "./dukluv/src/duv.h"
#include "loop_init.h"
// #include "./dukluv/src/misc.h"

uv_loop_t *create_loop()
{
    uv_loop_t *loop = malloc(sizeof(uv_loop_t));
    if (loop)
    {
        uv_loop_init(loop);
    }
    return loop;
}

// static duk_ret_t duv_main(duk_context *ctx, uv_loop_t *loop)
// {

//     duk_push_global_object(ctx);
//     // duk_dup(ctx, -1);
//     // duk_put_prop_string(ctx, -2, "global");

//     // duk_push_boolean(ctx, 1);
//     // duk_put_prop_string(ctx, -2, "dukluv");

//     // Load duv module into global uv
//     duk_push_c_function(ctx, dukopen_uv, 0);
//     duk_call(ctx, 0);
//     duk_put_prop_string(ctx, -2, "uv");

//     // // Replace the module loader with Duktape 2.x polyfill.
//     // duk_get_prop_string(ctx, -1, "Duktape");
//     // duk_del_prop_string(ctx, -1, "modSearch");
//     // duk_push_c_function(ctx, duv_mod_compile, 1);
//     // duk_put_prop_string(ctx, -2, "modCompile");
//     // duk_push_c_function(ctx, duv_mod_resolve, 1);
//     // duk_put_prop_string(ctx, -2, "modResolve");
//     // duk_push_c_function(ctx, duv_mod_load, 0);
//     // duk_put_prop_string(ctx, -2, "modLoad");
//     // duk_push_c_function(ctx, duv_loadlib, 2);
//     // duk_put_prop_string(ctx, -2, "loadlib");
//     // duk_pop(ctx);

//     // Put in some quick globals to test things.
//     // duk_push_c_function(ctx, duv_path_join, DUK_VARARGS);
//     // duk_put_prop_string(ctx, -2, "pathJoin");

//     // duk_push_c_function(ctx, duv_loadfile, 1);
//     // duk_put_prop_string(ctx, -2, "loadFile");

//     // // require.call({id:uv.cwd()+"/main.c"}, path);
//     // duk_push_c_function(ctx, duv_require, 1);
//     // {
//     //     // Store this require function in the module prototype
//     //     duk_push_global_stash(ctx);
//     //     duk_push_object(ctx);
//     //     duk_dup(ctx, -3);
//     //     duk_put_prop_string(ctx, -2, "require");
//     //     duk_put_prop_string(ctx, -2, "modulePrototype");
//     //     duk_pop(ctx);
//     // }
//     // duk_push_object(ctx);
//     // duk_push_c_function(ctx, duv_cwd, 0);
//     // duk_call(ctx, 0);
//     // duk_push_string(ctx, "/main.c");
//     // duk_concat(ctx, 2);
//     // duk_put_prop_string(ctx, -2, "id");
//     // duk_dup(ctx, 0);
//     // duk_call_method(ctx, 1);

//     uv_run(loop, UV_RUN_DEFAULT);

//     return 0;
// }

void loop_init()
{
    printf("loop_init!");
    uv_loop_t *loop = create_loop();
    duk_context *ctx = NULL;
    // uv_loop_init(&loop);

    // uv_setup_args(argc, argv);

    // if (argc < 2)
    // {
    //     fprintf(stderr, "Usage: dukluv script.js\n");
    //     exit(1);
    // }

    // Tie loop and context together
    ctx = duk_create_heap(NULL, NULL, NULL, &loop, NULL);
    if (!ctx)
    {
        fprintf(stderr, "Problem initiailizing duktape heap\n");
        return;
    }
    // duk_module_duktape_init(ctx);
    // duk_console_init(ctx, 0);
    // loop.data = ctx;

    // Stash argv for later access
    // duk_push_pointer(ctx, (void *)argv);
    // duk_push_int(ctx, argc);
    // if (duk_safe_call(ctx, duv_stash_argv, NULL, 2, 1))
    // {
    //     duv_dump_error(ctx, -1);
    //     uv_loop_close(&loop);
    //     duk_destroy_heap(ctx);
    //     return 1;
    // }
    // duk_pop(ctx);

    // inlined duv_main
    duk_push_global_object(ctx);
    duk_push_c_function(ctx, dukopen_uv, 0);
    duk_call(ctx, 0);
    duk_put_prop_string(ctx, -2, "uv");
    uv_run(loop, UV_RUN_DEFAULT);
    // end inlined duv_main

    // duk_push_c_function(ctx, duv_main, 1);
    // duk_push_string(ctx, argv[1]);
    // if (duk_pcall(ctx, 1))
    // {
    //     duv_dump_error(ctx, -1);
    //     uv_loop_close(&loop);
    //     duk_destroy_heap(ctx);
    //     return 1;
    // }

    uv_loop_close(loop);
    duk_destroy_heap(ctx);
    return;
}