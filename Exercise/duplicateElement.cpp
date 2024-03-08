#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
};

void DuplicateElementUsingHashing(struct Array arr)
{
    int max = arr.A[arr.size - 1];
    int min = arr.A[0];
    int *tempArr = new int[max + 1]();

    for (int i = 0; i < arr.size; i++)
    {
        tempArr[arr.A[i]]++;
    }

    for (int i = min; i < max + 1; i++)
    {
        if (tempArr[i] > 1)
            cout << "Element " << i << " has " << tempArr[i] << " duplicates\n";
    }

    delete[] tempArr;
}

int main()
{
    struct Array arr = {{3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 10};
    DuplicateElementUsingHashing(arr);
    return 0;
}