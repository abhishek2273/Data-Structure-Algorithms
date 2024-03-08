#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
};

int i, j, k;

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

// pair of element K--
void sumPairUnsorted(struct Array arr, int k)
{
    for (i = 0; i < arr.size - 1; i++)
    {
        for (j = i + 1; j < arr.size; j++)
        {
            if (arr.A[i] + arr.A[j] == k)
                printf("%d + %d = %d \n", arr.A[i], arr.A[j], k);
        }
    }
}

// pair of element using Hash-Table ---
void sumPairUnHash(struct Array arr, int k)
{
    int min = Min(arr);
    int max = Max(arr);

    int *tempArr = new int[max + 1]();
    for (i = 0; i < arr.size; i++)
    {
        if ((tempArr[k - arr.A[i]] > 0) && (k - arr.A[i] > 0))
        {
            // printf("%d+%d=%d\n", arr.A[i], k - arr.A[i], k);
             cout << arr.A[i] << " + " << k - arr.A[i] << " = " << k << endl;
        }
        tempArr[arr.A[i]]++;
    }

    delete[] tempArr;
}

int main()
{
    struct Array arr = {{6, 3, 8, 10, 16, 7, 5, 2, 9, 14}, 10};
    // sumPairUnsorted(arr, 26);
    sumPairUnHash(arr, 26);
    return 0;
}