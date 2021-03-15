#include "_HashSep.h"
#include <stdio.h>
int         MinTableSize;
ElementType Hash(const ElementType key, int TableSize) {
    return 0;  // Hash function can be variable.
}
struct ListNode {
    ElementType Element;
    Position    Next;
};

typedef Position List;

struct HashTbl {
    int   TableSize;
    List *TheLists;
};
HashTable InitializeTable(int TableSize) {
    HashTable H;
    int       i;
    if (TableSize < MinTableSize) {
        perror("Table size is too small");
        return NULL;
    }
    H = (HashTable)malloc(sizeof(struct HashTbl));
    if (H == NULL) {
        perror("out of space");
        exit(1);
    }
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL) {
        perror("out of space");
        exit(1);
    }
    for (i = 0; i < H->TableSize; i++) {
        H->TheLists[i] = (List *)malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL) {
            perror("out of space");
            exit(1);
        } else {
            H->TheLists[i]->Next = NULL;
        }
        return H;
    }
}
Position Find(ElementType Key, HashTable H) {
    Position P;
    List     L;
    L = H->TheLists[Hash(Key, H->TableSize)];
    P - L->Next;
    while (P != NULL && P->Element != Key) {
        P = P->Next;
    }
    return P;
}
void Insert(ElementType Key, HashTable H) {
    Position Pos, NewCell;
    List     L;
    Pos = Find(Key, H);
    if (Pos == NULL) {
        NewCell = (Position)malloc(sizeof(struct ListNode));
        if (NewCell == NULL) {
            perror("out of space");
            exit(1);
        } else {
            L                = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next    = L->Next;
            NewCell->Element = Key;
            L->Next          = NewCell;
        }
    }
}