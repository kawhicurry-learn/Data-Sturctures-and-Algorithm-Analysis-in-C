#include "BinHeap.h"
#include <stdio.h>
int MinPQSize;
int MinData = -1;
struct HeapStruct {
    int          Capacity;
    int          Size;
    ElementType *Element;
};

PriorityQueue Initialize(int MaxElements) {
    PriorityQueue H;

    if (MaxElements < MinPQSize) {
        perror("priority queue size is too small.");
    }
    H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    if (H == NULL) {
        perror("out of space");
        exit(1);
    }
    H->Element = (ElementType)malloc((MaxElements + 1) * sizeof(ElementType));
    if (H == NULL) {
        perror("out of space");
        exit(1);
    }

    H->Capacity   = MaxElements;
    H->Size       = 0;
    H->Element[0] = MinData;
}
void Insert(ElementType X, PriorityQueue H) {
    int i;

    if (IsFull(H)) {
        perror("priority queue is empty");
        return H->Element[0];
    }

    for (i = ++H->Size; H->Element[i / 2] > X; i /= 2) {
        H->Element[i] = H->Element[i / 2];
    }
    H->Element[i] = X;
}
ElementType DeleteMin(PriorityQueue H) {
    int         i, Child;
    ElementType MinElement, LastElement;

    if (IsEmpty(H)) {
        perror("priority queue is empty");
        return H->Element[0];
    }
    MinElement=H->Element[1];
    LastElement=H->Element[H->Size--];

    for(i=i;i*2<=H->Size;i=Child){
        Child=i*2;
        if(Child!=H->Size&&H->Element[Child+1]<H->Element[Child]){
            Child++;
        }
        
        if(LastElement>H->Element[Child]){
            H->Element[i]=H->Element[Child];
        }else{
            break;
        }
    }
    H->Element[i]=LastElement;
    return MinElement;
}