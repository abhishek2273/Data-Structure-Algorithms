// Merging, Set Operation (Union,Intersection)

#include <iostream>
using namespace std;

int i, j, k;

struct Array
{
    int A[20];
    int length;
    int size;
};
// Display Function()
void Display(struct Array arr)
{
    printf("\nElements are :\n");
    for (i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
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
    struct Array arr1 = {{2, 6, 10, 15, 25}, 5, 20};
    struct Array arr2 = {{3, 6, 7, 15, 22}, 5, 20};
    struct Array *arr3;

    // arr3 = Merge(&arr1, &arr2);
    // arr3 = Union(&arr1, &arr2);
    // arr3 = Intersection(&arr1, &arr2);
    arr3 = Difference(&arr1, &arr2);

    Display(*arr3);
    return 0;
}