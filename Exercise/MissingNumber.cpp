#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};
int i, j, k;

void Input(struct Array *arr)
{
    printf("Enter the number of elements (up to 20): ");
    cin >> arr->length;

    for (i = 0; i < arr->length; i++)
    {
        cin >> arr->A[i];
    }
    arr->size = arr->length * sizeof(int);
}

// Finding Single Missing Element in an Array(Sorted List- Natural Number)
int MissingElement(struct Array *arr)
{
    // Requirement :  Natural no, no of element and sorted
    int sum = 0, s;
    for (i = 0; i < 11; i++)
    {
        sum += arr->A[i];
    }
    s = (10 * (10 + 1)) / 2;

    int missingNumber = s - sum;
    return missingNumber;
}

// Sorted List
void MissingElementAnyOrder(struct Array *arr, int low, int high, int n)
{
    // Requirement : known Low,high, no of element and sorted
    int diff = low - 0;
    for (i = 0; i < n; i++)
    {
        if (arr->A[i] - i != diff)
        {
            while (diff < arr->A[i] - i)
            {
                printf("Missing Number is %d ", i + diff);
                diff++;
            }
        }
    }
}

// Unsorted Array
void MissingElementInUnsortedArray(struct Array arr, int low, int high, int n)
{
    // Requirement : known Low,high, no of element and sorted
    int *tempArr = (int *)malloc(high * sizeof(int));

    for (int i = 0; i < high; i++)
        tempArr[i] = 0;

    for (i = 0; i < n; i++)
    {
        tempArr[arr.A[i]]++;
    }

    cout << "Missing Elements: ";
    for (int i = low; i <= high; i++)
    {
        if (tempArr[i] == 0)
            cout << i << " ";
    }
    cout << endl;
    free(tempArr);
};

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 8, 9, 10}, 10, 10};
    struct Array arr1 = {{5, 8, 9, 10, 12, 13, 14, 15, 16, 17}, 20, 12};
    struct Array arrUnsorted = {{3, 7, 4, 9, 12, 11, 2, 10}, 20, 10};

    // cout << "Missing Number is " << MissingElement(&arr);
    // MissingElementAnyOrder(&arr1, 6, 17, 12);
    MissingElementInUnsortedArray(arrUnsorted, 1, 12, 10);

    return 0;
}