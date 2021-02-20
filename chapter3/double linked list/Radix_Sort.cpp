/*before radix_sort:
bucket_sort: Assume there are N number ranging from 1~M;
1.prepare M bucket that hold 1,2,...,M and initialize it to zero;
2.when N number if read, increse bucket to 1
3.print out the buckets which are 1*/

//原来没有代码呀，没事了，不过有空可以来写写。

/*radix_sort:
Assume there are N number ranging from 1~N^P-1(like 9999)
1.sort by lowest digit.
2.sort by higher digit.
...
P.sort by P digit.
P+1.print out.
NOTICE:digit represent any number,not only ten;
*/
// official data for test:64 8 216 512 27 729 0 1 343 125

#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
void BucketSort(int Array[], int N, int Range) {
  int i, tmp, *bucket=NULL;
  bucket = (int *)malloc((Range+1) * sizeof(int));
  if (bucket == NULL) {
    perror("buffer exceed");
    exit(1);
  }
  for (i = 0; i <= Range; i++) {
    bucket[i] = 0;
  }
  for (i = 0; i < N; i++) {
    tmp = Array[i];
    bucket[tmp]++;
  }
  for (i = 0; i <= Range; i++) {
    if (bucket[i] != 0) {
      while (bucket[i]--) {
        printf("%d\t", i);
      }
    }
  }
  free(bucket);
}
void RadixSort(int Array[], int N, int Digit) { int i=0; }//写完第一行发现好难写，理解理解就好
int main(void) {
  int *Array, N, Range,i;
  scanf_s("%d %d", &N, &Range);
  Array = (int *)malloc(N * sizeof(int));
  if (Array == NULL) {
    exit(1);
  }
  for (i = 0; i < N; i++) {
    scanf_s("%d", &Array[i]);
  }
  BucketSort(Array, N, Range);
  free(Array);
}