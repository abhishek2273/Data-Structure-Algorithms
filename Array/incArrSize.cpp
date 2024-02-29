// increasing size of array by using another array

#include <iostream>
using namespace std;

int main()
{
    int *p = new int[5];
    int *q = new int[10];
    int i;
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    // limited size of p;
    for (i = 0; i < 5; i++)
    {
        cout << p[i];
    }

    for (i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    cout << endl;
    // after p element transfer into q;
    q[5] = 100;
    for (i = 0; i < 6; i++)
    {
        cout << q[i];
    }

    delete[] p;
    p = q;
    q = NULL;

    cout << endl;
    for (i = 0; i < 6; i++)
    {
        cout << p[i];
    }

    return 0;
}