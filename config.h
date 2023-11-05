#define FREE_AT_EXIT
#define v1_arr_to_find_len (5)
static uint v1_arr_to_find[v1_arr_to_find_len];

static uint COUNT_2 = 0;
static uint LOOP_TIMES = 0;

void parse_args(int argc, const char *argv[]) {
    if (argc < 3) {
        printf("ERROR: Not enough args (%d). Format is [COUNT] [LOOP_TIMES]\n", argc);
        exit(1);
    }

    COUNT_2 = atoi(argv[1]);
    LOOP_TIMES = atoi(argv[2]);

    // printf("COUNT_2 = %ld, LOOP_TIMES = %ld\n", COUNT_2, LOOP_TIMES);

    v1_arr_to_find[0] = COUNT_2 / 2;
    v1_arr_to_find[1] = COUNT_2 / 2 + COUNT_2 / 6;
    v1_arr_to_find[2] = COUNT_2 / 2 + COUNT_2 / 5;
    v1_arr_to_find[3] = COUNT_2 / 2 + COUNT_2 / 4;
    v1_arr_to_find[4] =  COUNT_2 / 2 + COUNT_2 / 3;

    // for (uint i = 0; i < v1_arr_to_find_len; i++) {
    //     printf("%d\n", v1_arr_to_find[i]);
    // }
}