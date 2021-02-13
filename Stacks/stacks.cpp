#define EmptyTos (-1)
#define MinStackSize (5)
#define ElementType int
#include "stacks.h"
#include <stdio.h>
#include <stdlib.h>
struct StackRecord {
  int Capacity;
  int TopOfStack;
  ElementType *Array;
};

Stack CreateStack(int MaxElement) {
  Stack S;
  if (MaxElement < MinStackSize) {
    perror("Stack size is too small");
  }
  S = (struct StackRecord *)malloc(sizeof(struct StackRecord));
  if (S == NULL) {
    perror("out of space");
    exit(1);
  }
  S->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElement);
  if (S->Array == NULL) {
    perror("out of space");
  }
  S->Capacity = MaxElement;
  MakeEmpty(S);
  return S;
}
void DisposeStack(Stack S) {
  if (S != NULL) {
    free(S->Array);
    free(S);
  }
}
int IsEmpty(Stack S) { return S->TopOfStack == EmptyTos; }
void MakeEmpty(Stack S) { S->TopOfStack = EmptyTos; }
ElementType Top(Stack S) {
  if (!IsEmpty(S)) {
    return S->Array[S->TopOfStack];
  }
  perror("Empty stack");
  return 0;
}
void Pop(Stack S) {
  if (IsEmpty(S)) {
    perror("Empty Stack");
  } else {
    S->TopOfStack--;
  }
}

int main() {}