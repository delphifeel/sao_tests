#include "CCORE.h"
#include "config.h"

typedef struct {
    uint *v1;
    uint *v2;
    uint *v3;
    #ifdef DO_BUFF_EMBED
    uint8 *buff;
    #endif
} Tags;

int main(int argc, const char *argv[])
{
    parse_args(argc, argv);

    Tags *tags = CORE_MemAlloc(sizeof(Tags), 1);
    tags->v1 = CORE_MemAlloc(sizeof(uint), COUNT_2);
    tags->v2 = CORE_MemAlloc(sizeof(uint), COUNT_2);
    tags->v3 = CORE_MemAlloc(sizeof(uint), COUNT_2);
    #ifdef DO_BUFF_EMBED
    tags->buff = CORE_MemAlloc(64, COUNT_2);
    #endif

    // push
    for (uint i = 0; i < COUNT_2; i++) {
        tags->v1[i] = i;
        tags->v2[i] = i + 1;
        tags->v3[i] = i + 2;
        #ifdef DO_BUFF_EMBED
        CORE_MemSet(tags->buff + 64 * i, i % 200, 64);
        #endif
    }
    
    // find

    uint64 sum = 0;
    for (uint l_times = 0; l_times < LOOP_TIMES; l_times++) 
        for (uint to_find_i = 0; to_find_i < v1_arr_to_find_len; to_find_i++) {
            uint v1_to_find = v1_arr_to_find[to_find_i];
            for (uint i = 0; i < COUNT_2; i++) {
                if (tags->v1[i] == v1_to_find) {
                    sum += tags->v2[i] + tags->v3[i];
                    #ifdef DO_BUFF_EMBED
                    for (uint b = 0; b < 64; b++) {
                        uint8 *buff_start = tags->buff + 64 * i;
                        sum += buff_start[b];
                    }
                    #endif
                }
            }
        }

    CORE_DebugInfo("Sum: %ld\n", sum);

#ifdef FREE_AT_EXIT
    CORE_MemFree(tags);
#endif


    return 0;
}
