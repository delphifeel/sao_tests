#include "libCCORE/CCORE.h"
#include "config.h"

typedef struct {
    uint v1;
    uint v2;
    uint v3;
    uint64 v4;
    EMBED_BUFF
} Tag;

void Tag_Init(Tag *tag, uint i) 
{
    tag->v1 = i * 2;
    tag->v2 = i * 3;
    tag->v3 = i * 4;
}

bool Tag_Same(Tag tag1, Tag tag2)
{
    if (tag1.v1 != tag2.v1) {
        return false;
    }
    if (tag1.v2 != tag2.v2) {
        return false;
    }
    if (tag1.v3 != tag2.v3) {
        return false;
    }
    return true;
}
CVector_Define(Tag);

int main()
{
    CVector(Tag) v;
    CVector_Init(&v, COUNT);

    // push
    for (uint i = 0; i < COUNT; i++) {
        Tag t;
        Tag_Init(&t, i);
        CVector_Push(&v, t);
    }
    
    // find
    Tag tag_to_find;
    Tag_Init(&tag_to_find, COUNT / 2);
    for (uint i = 0; i < v.size; i++) {
        if (Tag_Same(tag_to_find, CVector_Get(&v, i))) {
            CORE_DebugInfo("We found it\n");
        }
    }

#ifdef FREE_AT_EXIT
    CVector_Free(&v);
#endif


    return 0;
}
