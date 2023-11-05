#include "CCORE.h"
#include "config.h"

typedef struct {
    uint v1;
    uint v2;
    uint v3;
    #ifdef DO_BUFF_EMBED
    uint8 buff[64];
    #endif
} Tag;


void tag_print(Tag *t)
{
    printf("[Tag] buf: ");
    for (uint i = 0; i < sizeof(t->buff); i++) {
        printf("%d, ", t->buff[i]);
    }
    printf("\n");
}

CVector_Define(Tag);

int main(int argc, const char *argv[])
{
    parse_args(argc, argv);

    CVector(Tag) v;
    CVector_Init(&v, COUNT_2);
    v.size = COUNT_2;

    // push
    for (uint i = 0; i < COUNT_2; i++) {
        Tag *t = CVector_GetPtr(&v, i);
        t->v1 = i;
        t->v2 = i + 1;
        t->v3 = i + 2;
        #ifdef DO_BUFF_EMBED
        CORE_MemSet(t->buff, i % 200, 64);
        #endif

        // if (i == 0) {
        //     tag_print(t);
        // }
    }
    
    // find
    uint64 sum = 0;
    for (uint l_times = 0; l_times < LOOP_TIMES; l_times++) 
        for (uint to_find_i = 0; to_find_i < v1_arr_to_find_len; to_find_i++) {
            uint v1_to_find = v1_arr_to_find[to_find_i];
            for (uint i = 0; i < v.size; i++) {
                Tag *t = CVector_GetPtr(&v, i);
                if (t->v1 == v1_to_find) {
                    sum += t->v2 + t->v3;
                    #ifdef DO_BUFF_EMBED
                    for (uint b = 0; b < 64; b++) {
                        sum += t->buff[b];
                    }
                    #endif
                }
            }
        }

    CORE_DebugInfo("Sum: %ld\n", sum);

#ifdef FREE_AT_EXIT
    CVector_Free(&v);
#endif


    return 0;
}
