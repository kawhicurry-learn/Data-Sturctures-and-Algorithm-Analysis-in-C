#ifndef _LeftHeap_H
struct TreeNode;
typedef struct TreeNode *PriorityQueue;
typedef int ElementType;
/*Minimal set of priority queue operations 
Note that nodes will be shared among several leftist heaps after a merge;
the user must make sure to not use the old leftist heaps*/

PriorityQueue Initilaize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2);

#define Insert(X,H) (H=Insert1((X),H))
#define DeleteMin(X,H) (H=DeleteMin1(H))

PriorityQueue Insert1(ElementType X,PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

#endif
