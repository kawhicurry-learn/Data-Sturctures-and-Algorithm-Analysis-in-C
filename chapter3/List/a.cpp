#include <stdio.h>
#include <stdlib.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef double ElementType; //这行是自己加的，为了保证程序正确

struct Node {
  ElementType Element;
  Position Next;
};

int IsEmpty(List L) { return L->Next == NULL; }
int IsLast(Position P, List L) { return P->Next == NULL; }
Position Find(ElementType X, List L) {
  Position P;
  P = L->Next;
  while (P != NULL && P->Element != X) {
    P = P->Next;
  }
  return P;
}
void Delete(ElementType X, List L) {
  Position P, TmpCell;
  P = FindPrevious(X, L);
  if (!IsLast(P, L)) {
    TmpCell = P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
  }
}
Position FindPrevious(ElementType X, List L) {
  Position P;
  while (P->Next != NULL && P->Next->Element != X) {
    P = P->Next;
  }
  return P;
}
/*Insert after legal position P*/
void Insert(ElementType X, List L, Position P) {
  Position TmpCell;
  TmpCell =(struct Node*)malloc(sizeof(struct Node));
  if (TmpCell == NULL) {
    perror("Out of space!");
  }
  TmpCell->Element = X;
  TmpCell->Next = P->Next;
  P->Next = TmpCell;
}
void DeleteList(List L) {
  Position P, Tmp;
  P = L->Next;
  L->Next = NULL;
  while (P != NULL) {
    Tmp = P->Next;
    free(P);
    P = Tmp;
  }
}
