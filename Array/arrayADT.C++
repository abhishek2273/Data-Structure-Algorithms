#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i];
    }
};

int main()
{
    struct Array arr;
    int n, i;
    cout << "enter size of array : ";
    cin >> arr.size;

    // creating array inside heap after taking input
    arr.A = new int(arr.size * sizeof(int));
    // arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    cout << "Enter of a number";
    cin >> n;

    cout << "Enter all element here\n";
    for (i = 0; i < n; i++)
    {
        cin >> arr.A[i];
    }
    arr.length = n;

    display(arr);
    return 0;
}