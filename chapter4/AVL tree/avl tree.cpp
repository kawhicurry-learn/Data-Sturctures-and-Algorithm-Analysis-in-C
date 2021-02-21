#include "avl_tree.h"
#define ElementType char
#include < stdio.h >
#include < stdlib.h >

struct AvlNode {
    ElementType Element;
    AvlTree     Left;
    AvlTree     Right;
    int         Height;
};
int Height(Position P) {
        if (P == NULL) {
            return -1;
    } else
        return P->Height;
}