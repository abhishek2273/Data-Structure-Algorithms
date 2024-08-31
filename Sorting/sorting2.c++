// Quick sort/Partition
// Merge sort (Iterative/Recursive)

#include <bits/stdc++.h>
using namespace std;

void swap(int &i, int &j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}

// 1. Partition (QS)
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);

        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j)
        {
            swap(A[i], A[j]);
        }
    } while (i < j);

    {
        swap(A[l], A[j]);
        return j;
    }
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

// 2. Merge function
void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (int i = l; i <= h; i++)
        A[i] = B[i];
}

// Merge sort(Iterative procedure)
void IMergeSort(int A[], int n)
{
    int p, i, l, h, mid;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
    }
    if (p / 2 < n)
    {
        Merge(A, 0, (p / 2 - 1), n);
    }
}

// Merge sort(Recursive procedure)
void MergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

int main()
{

    int arr[] = {11, 13, 7, 12, 16, 9, 24, 10, 5, 7, 3, 2, 6998};
    int n = sizeof(arr) / sizeof(int);

    // QuickSort(arr, 0, n - 1);
    // IMergeSort(arr, n);
    MergeSort(arr, 0, n);

    for (auto arr : arr)
    {
        cout << arr << " ";
    }
    cout << "\n";
    return 0;
}