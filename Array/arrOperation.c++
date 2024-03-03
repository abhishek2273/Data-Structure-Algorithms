// Merging, Set, Union

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

    for (; j < arr1->length; j++)
        arr3->A[k++] = arr2->A[j];

    // set length arr3()
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
};

int main()
{
    struct Array arr1 = {{2, 6, 10, 15, 25}, 20, 5};
    struct Array arr2 = {{3, 5, 18, 20, 22}, 20, 5};
    struct Array *arr3;

    arr3 = Merge(&arr1, &arr2);

    Display(*arr3);
    return 0;
}