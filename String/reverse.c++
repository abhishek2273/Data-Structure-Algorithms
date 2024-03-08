#include <iostream>
using namespace std;

int main()
{
    char A[] = "Python";
    char B[7];
    char t;
    int i, j;

    // //Method 1
    // for (i = 0; A[i] != '\0'; i++)
    // {
    // }
    // i = i - 1;
    // for (j = 0; i >= 0; i--, j++)
    // {
    //     B[j] = A[i];
    // }
    // B[j] = '\0';
    // cout << B;

    // Method 2--------------------
    for (j = 0; A[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    cout << A;
    return 0;
}