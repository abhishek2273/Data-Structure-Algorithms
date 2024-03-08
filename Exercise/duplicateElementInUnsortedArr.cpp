#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
};

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.size; i++)
        if (arr.A[i] < min)
            min = arr.A[i];
    return min;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.size; i++)
        if (arr.A[i] > max)
            max = arr.A[i];
    return max;
}

void duplicateElement(struct Array arr)
{
    int i, j, count;

    for (i = 0; i < arr.size - 1; i++)
    {
        count = 1;

        if (arr.A[i] != -1)
        {
            for (j = i + 1; j < arr.size; j++)
            {
                if (arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            }
        }
        if (count > 1)
            printf("%d is %d times\n", arr.A[i], count);
    }
}

// Using Hashing
void DhashElement(struct Array arr)
{
    int i;
    int max = Max(arr);
    int min = Min(arr);

    int *tempArr = new int[max + 1]();
    for (i = 0; i < arr.size; i++)
        tempArr[arr.A[i]]++;

    for (i = min; i < max + 1; i++)
    {
        if (tempArr[i] > 1)
            cout << "Element " << i << " has " << tempArr[i] << " duplicates\n";
    }
}

int main()
{
    struct Array arr = {{8, 6, 5, 4, 6, 8, 6, 8, 2, 7}, 10};

    // duplicateElement(arr);
    DhashElement(arr);
    return 0;
}