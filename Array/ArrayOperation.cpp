#include <iostream>
using namespace std;

int i, j, k;
struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are :\n");
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    int i;

    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int i, x = 0;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }

    return -1;
}

// improve linear search
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Linear Search
int LinearSearch(struct Array *arr, int key)
{
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }
    return -1;
}

// Binary Search (if-else)
int BinarySearchLoop(struct Array arr, int key)
{
    int low = 0, high, mid;
    high = arr.length - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// Binary Search (Recursive)
int RBinSearch(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            return RBinSearch(a, l, mid - 1, key);
        }
        else
        {
            return RBinSearch(a, mid - 1, h, key);
        }
    }

    return -1;
}

// Get method()
int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

// Get method()
int Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}

// Max()
int MAX(struct Array arr)
{
    int max = arr.A[0];
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

// Min()
int MIN(struct Array arr)
{
    int min = arr.A[0];
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

// SUM()
int SUM(struct Array arr)
{
    int sum = 0;
    for (i = 0; i < arr.length; i++)
        sum = sum + arr.A[i];

    return sum;
}

// Average()
float Average(struct Array arr)
{
    return (float)SUM(arr) / arr.length;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
    int key = 6;

    // Append(&arr, 10);
    // Insert(&arr, 0, 100);
    // printf("%d\n", Delete(&arr, 2));
    // cout << "key :" << key << "\nindex :" << LinearSearch(&arr, key);
    // printf("index :%d", BinarySearchLoop(arr, 5));
    // printf("index :%d", RBinSearch(arr.A,0,arr.length, 5));

    // printf("\n%d", Get(arr, 0));
    // Set(&arr, 0, 25);
    printf("\nMax :%d", MAX(arr));
    printf("\nMin :%d", MIN(arr));
    printf("\nSum :%d", SUM(arr));
    printf("\nAvg :%.2f", Average(arr));
    Display(arr);
    return 0;
}