#include "avl_tree.h"
#define ElementType char
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

struct AvlNode {
    ElementType Element;
    AvlTree     Left;
    AvlTree     Right;
    int         Height;
};
int main(void) {
    return 0;
}
static int Height(Position P) {
        if (P == NULL) {
            return -1;
    } else
        return P->Height;
}
static Position SingleRotateWithLeft(Position K2) {
    Position K1;
    K1         = K2->Left;
    K2->Left   = K1->Right;
    K1->Right  = K2;
    K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = max(Height(K1->Left), K2->Height) + 1;
    return K1;
}
static Position SingleRotateWithRight(Position K2) {
    Position K1;
    K1         = K2->Right;
    K2->Right  = K1->Left;
    K1->Left   = K2;
    K2->Height = max(Height(K2->Right), Height(K2->Left)) + 1;
    K1->Height = max(Height(K1->Right), K2->Height) + 1;
    return K1;
}
static Position DoubleRotateWithLeft(Position K3) {
    K3->Left = SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}
static Position DoubleRotateWithRight(Position K3) {
    K3->Left = SingleRotateWithLeft(K3->Left);
    return SingleRotateWithRight(K3);
}
AvlTree Insert(ElementType X, AvlTree T) {
        if (T == NULL) {
            T = (AvlTree)malloc(sizeof(struct AvlNode));
                if (T == NULL) {
                    perror("out of space");
                    exit(1);
                } else {
                    T->Element = X;
                    T->Height  = 0;
                    T->Left = T->Right = NULL;
                }
        } else if (X < T->Element) {
            T->Left = Insert(X, T->Left);
            if (Height(T->Left) - Height(T->Right) == 2)
                if (X < T->Left->Element)
                    T = SingleRotateWithLeft(T);
                else
                    T = DoubleRotateWithLeft(T);
        } else if (X > T->Element) {
            T->Right = Insert(X, T->Right);
            if (Height(T->Right) - Height(T->Left) == 2)
                if (X > T->Right->Element)
                    T = SingleRotateWithRight(T);
                else
                    T = DoubleRotateWithRight(T);
    }
    T->Height = max(Height(T->Left), Height(T->Right));
    return T;
}
