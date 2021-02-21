#ifndef _AvlTree_H
#define ElementType char
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMax(AvlTree T);
Position FindMin(AvlTree T);
AvlTree  Insert(ElementType X, AvlTree T);
AvlTree  Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);
#endif