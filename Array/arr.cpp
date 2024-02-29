// creating Array stack and heap

#include <iostream>
using namespace std;

int main()
{
    //stack
    int A[5] = {2, 4, 6, 8, 10};
    int *p; //heap
    int i;

    p = (int *)malloc(5 * sizeof(int));

    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    for (i = 0; i < 5; i++)
    {
        cout << A[i];
    }
    printf("\n");

    for (i = 0; i < 5; i++)
    {
        cout << p[i];
    }
    return 0;
}