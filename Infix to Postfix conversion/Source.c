/*
测试数据如下：
a+b*c+(d*e+f)*g
1+2*3+(4*5+6)*7
标准答案如下：
abc*+de*f+g*+
123*+45*6+7*+
*/
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 50
int main() {
  char Infix[LENGTH] = {0}, Postfix[LENGTH] = {0};
  char *p1 = Infix, *p2 = Postfix, tmpch;
  Stack S;
  S = CreateStack();
  scanf_s("%s", Infix, LENGTH);
  while (*p1 != '\0') {
    if (*p1 < 57 && *p1 > 48) {
      *p2 = *p1;
      p2++;
      p1++;
      continue;
    }
    if (*p1 == ')') {
      tmpch = Top(S);
      while (tmpch != '(') {
        *p2 = tmpch;
        p2++;
        Pop(S);
        tmpch = Top(S);
      }
      Pop(S);
      p1++;
      continue;
    }
    if (*p1 == '(') {
      Push(*p1, S);
      p1++;
      continue;
    }
    if (IsEmpty(S)) {
      Push(*p1, S);
      p1++;
      continue;
    }
    if (JudgePrim(*p1) > JudgePrim(Top(S))) {
      Push(*p1, S);
    } else {
      while (Top(S)!='('&&JudgePrim(*p1) <= JudgePrim(Top(S))) {//out first,then in another
        *p2 = Top(S);
        p2++;
        Pop(S);
      }
      Push(*p1, S);
    }
    p1++;
  }
  while (!IsEmpty(S)) {
    *p2 = Top(S);
    Pop(S);
    p2++;
  }
  printf("%s", Postfix);
  return 0;
}

struct Node {
  char Element;
  PtrToNode Next;
};

int JudgePrim(char X) {
  switch (X) {
  case '+':;
  case '-':
    return 1;
  case '*':;
  case '/':
    return 2;
  default:
    return 0;
  }
}
int IsEmpty(Stack S) { return S->Next == NULL; }
Stack CreateStack(void) {
  Stack S;

  S = (Stack)malloc(sizeof(struct Node));
  if (S == NULL) {
    perror("out of space");
    exit(1);
  }
  S->Next = NULL; // should exist here,machine may not make it NULL.
  MakeEmpty(S);
  return S;
} /*That means the TOP Node of the stack store no element;
  but S is always the entry of the stack*/
void MakeEmpty(Stack S) {
  if (S == NULL) {
    perror("must create first");
  } else {
    while (!IsEmpty(S)) {
      Pop(S);
    }
  }
}
void Push(char X, Stack S) {
  PtrToNode TmpCell;
  TmpCell = (PtrToNode)malloc(sizeof(struct Node));
  if (TmpCell == NULL) {
    perror("out of space");
    exit(3);
  } else {
    TmpCell->Element = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
  }
}
char Top(Stack S) {
  if (!IsEmpty(S)) {
    return S->Next->Element;
  }
  //perror("Empty stack:1");this functure needn't take effective in this project.
  return 0;
}
void Pop(Stack S) {
  PtrToNode FirstCell;
  if (IsEmpty(S)) {
    perror("Empty Stack:2");
    exit(4);
  } else {
    FirstCell = S->Next;
    S->Next = S->Next->Next;
    free(FirstCell);
  }
}
void DisposeStack(void) { ; }
