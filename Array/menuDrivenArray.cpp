// All Array Operation in one single Main() function

#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int length;
    int size;
};
int i, j, k;

void Display(struct Array arr)
{
    printf("Elements are :\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

// Append()
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

// Insert()
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

// Delete()
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

// Reverse an array()
void Reverse(struct Array *arr)
{
    int temp;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void Reverse2(struct Array *arr)
{
    int *B;
    B = new int(arr->length * sizeof(int));

    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

// Left Shifting/ Rotate();
void LeftShifting(struct Array *arr)
{
    int firstElement = arr->A[0];
    for (i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = firstElement;
}

// Right Shifting/ Rotate();
void RightShifting(struct Array *arr)
{
    int lastElement = arr->A[arr->length - 1];

    for (i = arr->length - 1; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = lastElement;
}

// check Array is Sort or not;
int isArraySORT(struct Array arr)
{
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i + 1] < arr.A[i])
        {
            return 0;
        }
    }
    return true;
}

// insert a Number in Sorted Array
void insertNumberInSortedArray(struct Array *arr, int x)
{
    i = arr->length - 1;
    if (arr->length == arr->size)
    {
        return;
    }

    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

// move negative integer in left side:
void moveNegativeInLeftSide(struct Array *arr)
{
    i = 0;
    j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] > 0)
            j--;
        if (i < j)
        {
            swap(arr->A[i], arr->A[j]);
        }
    }
}

// Merge()
struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    // set length arr3()
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
};

// Union for SORTED Array---
struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;
}

// Intersection for SORTED Array---
struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
}

// Difference for SORTED Array---
struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 10;
}

int main()
{
    // initialization
    struct Array arr1;
    int choice;
    int x, index;

    printf("Enter Size of array ");
    cin >> arr1.size;
    // allocate memory in heap
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    do
    {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. EXit\n");

        printf("Enter your choice : ");
        cin >> choice;

        switch (choice)
        {
        case 1:
            printf("enter the index and element");
            cin >> index >> x;
            Insert(&arr1, index, x);
            break;
        case 2:
            printf("enter the index ");
            cin >> index;
            Delete(&arr1, index);
            break;
        }
    } while (choice < 6);

    return 0;
}