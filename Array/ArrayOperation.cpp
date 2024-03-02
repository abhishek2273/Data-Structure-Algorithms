#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("Elements are :\n");
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

void Delete(struct Array *arr, int index)
{
    if (index >= 0 && index <= arr->length)
    {
    }
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};

    Append(&arr, 10);
    Insert(&arr, 0, 100);
    Display(arr);
    return 0;
}