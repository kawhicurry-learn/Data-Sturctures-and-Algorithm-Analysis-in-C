#include "LeftHeap.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    ElementType   Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int           Npl;  // length of the shortest path from X to a node;
};
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2) {
    if (H1 == NULL) {
        return H2;
    }
    if (H2 == NULL) {
        return H1;
    }
    if (H1->Element < H2->Element) {
        return Merge1(H1, H2);
    } else {
        return Merge1(H2, H1);
    }
}
static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2) {
    if (H1->Left == NULL) {
        H1->Left = H2;
    } else {
        H1->Right = Merge(H1->Right, H2);
        if (H1->Left->Npl < H1->Right->Npl) {
            SwapChildren(H1);
        }
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}
PriorityQueue Insert1(ElementType X, PriorityQueue H) {
    PriorityQueue SingelNode;

    SingelNode = (PriorityQueue)malloc(sizeof(struct TreeNode));
    if (SingelNode == NULL) {
        perror("out of space");
    } else {
        SingelNode->Element = X;
        SingelNode->Npl     = 0;
        SingelNode->Left = SingelNode->Right = NULL;
        H                                    = Merge(SingelNode, H);
    }
    return H;
}
PriorityQueue DeleteMin1(PriorityQueue H){
    PriorityQueue LeftHeap,RightHeap;

    if(IsEmpty(H)){
        return H;
    }

    LeftHeap=H->Left;
    RightHeap=H->Right;
    free(H);
    return Merge(LeftHeap,RightHeap);
}
