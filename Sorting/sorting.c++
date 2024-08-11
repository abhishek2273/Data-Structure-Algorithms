#include <bits/stdc++.h>
using namespace std;

int i, j, k;

void swap(int &i, int &j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}

// 1. Bubble Sort
void BubbleSort(int arr[], int n)
{
    printf("%s", "Bubble Sort: ");
    for (i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

// 2. Insertion Sort
void InsertionSort(int arr[], int n)
{
    printf("%s ", "Insertion Sort: ");
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        int x = arr[i];

        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

// 3. Selection Sort
void SelectionSort(int arr[], int n)
{
    printf("%s ", "Selection Sort: ");
    for (i = 0; i < n - 1; ++i)
    {
        for (j = k = i; j < n; ++j)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(arr[i], arr[k]);
    }
}

int main()
{

    int arr[] = {8, 5, 7, 3, 2};
    int size = sizeof(arr) / sizeof(int);

    // BubbleSort(arr, size);
    // InsertionSort(arr, size);
    SelectionSort(arr, size);

    for (auto arr : arr)
    {
        cout << arr << " ";
    }
    cout << "\n";

    return 0;
}