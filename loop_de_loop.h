#if !defined(LOOP_DE_LOOP_H_INCLUDED)
#define LOOP_DE_LOOP_H_INCLUDED

#include "./dukluv/src/duv.h"
#include "loop_init.h"

#if defined(__cplusplus)
extern "C"
{
#endif

    // extern int loop_de_loop(int argc, char *argv[]);
    extern loop_init_rtn loop_de_loop();

#if defined(__cplusplus)
}
#endif /* end 'extern "C"' wrapper */

#endif /* LOOP_DE_LOOP_H_INCLUDED */
