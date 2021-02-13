#ifndef _Stack_h
#define ElementType int

struct StackRecord;
typedef struct StackRecord *Stack;

  int IsEmpty(Stack S);
  Stack CreateStack(void);
  void DisposeStack(Stack S);
  void MakeEmpty(Stack S);
  void Push(ElementType X, Stack S);
  ElementType Top(Stack S);
  void Pop(Stack S);
  ElementType TopAndPop(Stack S);
#endif 