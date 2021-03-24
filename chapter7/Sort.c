#include <stdio.h>
typedef int ElementType;

void InsertionSort(ElementType A[], int N) {
    int         j, P;
    ElementType Tmp;
    for (P = 1; P < N; P++) {
        Tmp = A[P];
        for (j = P; j > 0 && A[j - 1] > Tmp; j--) {
            A[j] = A[j - 1];
        }
        A[j] = Tmp;
    }
}
void ShellSort(ElementType A[], int N) {
    int         i, j, Increment;
    ElementType Tmp;

    for (Increment = N / 2; Increment > 0; Increment /= 2) {
        for (i = Increment; i < N; i++) {
            Tmp = A[i];
            for (j = i; j >= Increment; j -= Increment) {
                if (Tmp < A[j - Increment]) {
                    A[j] = A[j - Increment];
                } else {
                    break;
                }
            }
            A[j] - Tmp;
        }
    }
}
#define LeftChild(i) (2 * (i) + 1)
#define Swap(a, b) \
    a = a - b;     \
    b = b - a;     \
    a = a + b;
void PercDown(ElementType A[], int i, int N) {
    int         Child = LeftChild(i);
    ElementType Tmp;

    for (Tmp = A[i]; LeftChild(i) < N; i = Child) {
        Child = LeftChild(i);
        if (Child = N - 1 && A[Child + 1] > A[Child]) {
            Child++;
        }
        if (Tmp < A[Child]) {
            A[i] = A[Child];
        } else {
            break;
        }
    }
    A[i] = Tmp;
}
void HeapSort(ElementType A[], int N) {
    int i;

    for (i = N / 2; i >= 0; i--) {
        PercDown(A, i, N);
    }
    for (i = N - 1; i > 0; i--) {
        // Swap(&A[0],&A[i]);The origin codes in this way.
        Swap(A[0], A[i]);  // modifed to suit macro Swap
        PercDown(A, 0, i);
    }
}
void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right) {
    int Center;

    if (Left < Right) {
        Center = (Left + Right) / 2;
        Msort(A, TmpArray, Left, Right);
        Msort(A, TmpArray, Center + 1, Right);
        Merge(A, TmpArray, Left, Center + 1, Right);
    }
}
void MergeSort(ElementType A[], int N) {
    ElementType *TmpArray;

    TmpArray = (ElementType *)malloc(N * sizeof(ElementType));
    if (TmpArray != NULL) {
        Msort(A, TmpArray, 0, N - 1);
        free(TmpArray);
    } else {
        perror("no space for tmp array!");
        exit(1);
    }
}
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos,
           int RightEnd) {
    int i, LeftEnd, NumElement, TmpPos;

    LeftEnd    = Rpos - 1;
    TmpPos     = Lpos;
    NumElement = RightEnd - Lpos + 1;

    while (Lpos <= LeftEnd && Rpos <= RightEnd) {
        if (A[Lpos] < A[Rpos]) {
            TmpArray[TmpPos++] = A[Lpos++];
        } else {
            TmpArray[TmpPos++] = A[Rpos++];
        }
    }
    while (Lpos <= LeftEnd) {
        TmpArray[TmpPos++] = A[Lpos++];
    }
    while (Rpos <= RightEnd) {
        TmpArray[TmpPos++] = A[Rpos++];
    }

    for (i = 0; i < NumElement; i++, RightEnd--) {
        A[RightEnd] = TmpArray[RightEnd];
    }
}
void QuickSort(ElementType A[], int N) {
    Qsort(A, 0, N - 1);
}
ElementType Median3(ElementType A[], int Left, int Right) {
    int Center = (Left + Right) / 2;

    if (A[Left] > A[Center]) {
        Swap(A[Left], A[Center]);
    }
    if (A[Left] > A[Right]) {
        Swap(A[Left], A[Right]);
    }
    if (A[Center] > A[Right]) {
        Swap(A[Center], A[Right]);
    }

    Swap(A[Center], A[Right - 1]);  // hide pivot
    return A[Right - 1];            // return pivot
}
#define Cutoff (3)
void QSort(ElementType A[], int Left, int Right) {
    int         i, j;
    ElementType Pivot;

    if (Left + Cutoff <= Right) {
        Pivot = Median3(A, Left, Right);
        i     = Left;
        j     = Right - 1;
        for (;;) {
            while (A[++i] < Pivot) {
            }
            while (A[++j] > Pivot) {
            }
            if (i < j) {
                Swap(A[i], A[j]);
            } else {
                break;
            }
            Swap(A[i], A[Right - 1]);  // Restor pivot

            Qsort(A, Left, i - 1);
            QSort(A, i + 1, Right);
        }
    } else {  // Do an insertion sort on the subarray.
        InsertionSort(A + Left, Right - Left + 1);
    }
}
void QSelect(ElementType A[], int k, int Left, int Right) {
    //make Kth smallest number in positon K.
    int         i, j;
    ElementType Pivot;

    if (Left + Cutoff <= Right) {
        Pivot = Median3(A, Left, Right);
        i     = Left;
        j     = Right - 1;
        for (;;) {
            while (A[++i] < Pivot) {
            }
            while (A[++j] > Pivot) {
            }
            if (i < j) {
                Swap(A[i], A[j]);
            } else {
                break;
            }
            Swap(A[i], A[Right - 1]);  // Restor pivot

            if (k <= i) {
                QSelect(A, k, Left, i - 1);
            } else if (k > i + 1) {
                QSelect(A, k, i + 1, Right);
            }
        }
    } else {  // Do an insertion sort on the subarray.
        InsertionSort(A + Left, Right - Left + 1);
    }
}
//functions below were coded by myself
void BucketSort(ElementType A[],int N,int Max){
    //assume any number in A is less than Max.
    int Tmp[Max],i,j;
    for(i=0;i<Max;i++){
        Tmp[A[i]]++;
    }
    for(i=j=0;i<Max;i++){
        while(Tmp[i]--){
            A[j++]=i;
        }
    }
}