#ifndef header
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStadck(Stack S);
void MakeEmpty(Stack S);
void Push(char X, Stack S);
char Top(Stack S);
void Pop(Stack S);

#endif // !header
/*
�����������£�
a+b*c+(d*e+f)*g
1+2*3+(4*5+6)*7
��׼�����£�
abc*+de*f+g*+
123*+45*6+7*+
*/