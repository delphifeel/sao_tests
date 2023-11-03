#define COUNT (99999999)
#define FREE_AT_EXIT
//#define DO_BUFF_EMBED

#ifdef DO_BUFF_EMBED
#define EMBED_BUFF uint8 buff[128];
#else
#define EMBED_BUFF
#endif
