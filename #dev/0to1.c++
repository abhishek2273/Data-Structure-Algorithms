#include <iostream>
using namespace std;

int binaryToDecimal(int n)
{
    int binary = 0;
    int base = 1;
    while (n)
    {
        binary += (n % 2) * base;
        n /= 2;
        base *= 10;
    }
    return binary;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        cout << binaryToDecimal(n) << endl;
    }
    return 0;
}