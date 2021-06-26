#include "sort.h"

void Swap(string *x, string *y)
{
    string temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* insertion sort */
void InsertionSort(ElementType A[], int N)
{
    int j, P;
    ElementType Tmp;

    for (P = 1; P < N; P++)
    {
        Tmp = A[P];
        for (j = P; j > 0 && A[j - 1] > Tmp; j--)
        {
            A[j] = A[j - 1];
        }
        A[j] = Tmp;
    }
}
ElementType Median3(ElementType A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;

    if (A[Left] > A[Center])
    {
        Swap(&A[Left], &A[Center]);
    }
    if (A[Left] > A[Right])
    {
        Swap(&A[Left], &A[Right]);
    }
    if (A[Center] > A[Right])
    {
        Swap(&A[Center], &A[Right]);
    }

    /* Invariant: A[ Left ] <= A[ Center ] <= A[ Right ] */

    Swap(&A[Center], &A[Right - 1]); /* Hide pivot */

    return A[Right - 1]; /* Return pivot */
}

#define Cutoff (3) //截止

void Qsort(ElementType A[], int Left, int Right)
{
    int i, j;
    ElementType Pivot;

    if (Left + Cutoff <= Right)
    {
        Pivot = Median3(A, Left, Right);
        i = Left;
        j = Right - 1;

        for (;;)
        {
            while (A[++i] < Pivot)
            {
                //结束循环后 A[i] >= Pivot
            }
            while (A[--j] > Pivot)
            {
                //结束循环后 A[j] <= Pivot
            }
            if (i < j)
            {
                Swap(&A[i], &A[j]);
            }
            else
            {
                break;
            }
        }

        Swap(&A[i], &A[Right - 1]); /* Restore pivot */

        Qsort(A, Left, i - 1);
        Qsort(A, i + 1, Right);
    }
    else /* Do an insertion sort on the subarray */
    {
        InsertionSort(A + Left, Right - Left + 1); //Right - Left + 1 < 4 ?
    }
}

void Quicksort(ElementType A[], int N)
{
    Qsort(A, 0, N - 1);
}