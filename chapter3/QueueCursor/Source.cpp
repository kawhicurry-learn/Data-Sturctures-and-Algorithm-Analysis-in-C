#include "Header.h"
#include <stdio.h>
#include <stdlib.h>

struct QueueRecord {
  int Capacity;
  int Front;
  int Rear;
  int Size;
  ElementType *Array;
};
int main() {}

int IsEmpty(Queue Q) { return Q->Size == 0; }
int IsFull(Queue Q) { return Q->Capacity == Q->Size; }
void MakeEmpty(Queue Q) {
  Q->Size = 0;
  Q->Front = 1;
  Q->Rear = 0;
}
static int Succ(int Value, Queue Q) {
  if (++Value == Q->Capacity) {
    Value = 0;
  }
  return Value;
}
void Enqueue(ElementType X, Queue Q) {
  if (IsFull(Q)) {
    perror("Full queue");
  } else {
    Q->Size++;
    Q->Rear = Succ(Q->Rear, Q);
    Q->Array[Q->Rear] = X;
  }
}
Queue CreateQueue(int MaxElement) {
  Queue Q;
  Q = (Queue)malloc(sizeof(struct QueueRecord));
  if (Q == NULL) {
    perror("out of space");
    exit(1);
  }
  if (!IsEmpty(Q)) {
    MakeEmpty(Q);
  }
  Q->Capacity = MaxElement;
  Q->Array = (ElementType *)malloc(MaxElement * sizeof(ElementType));
  return Q;
}
ElementType Front(Queue Q) {
  ElementType X = 0;
  // input the element here;
  Q->Array[Q->Rear] = X;
  Q->Size++;
  Q->Rear++;
}
