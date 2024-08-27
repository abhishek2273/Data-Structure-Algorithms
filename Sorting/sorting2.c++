// Quick sort/Partition

#include <bits/stdc++.h>
using namespace std;

void swap(int &i, int &j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}

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

int main()
{

    int arr[] = {11, 13, 7, 12, 16, 9, 24, 10, 5, 7, 3, 2,6998};
    int n = sizeof(arr) / sizeof(int);

    QuickSort(arr, 0, n-1);

    for (auto arr : arr)
    {
        cout << arr << " ";
    }
    cout << "\n";
    return 0;
}