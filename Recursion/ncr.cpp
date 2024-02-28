// Combination Formula(nCr) = n!/r!(n-r)!

#include <iostream>
using namespace std;

int NCR(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    return NCR(n - 1, r - 1) + NCR(n - 1, r);
}

int main()
{
    cout << "nCR : " << NCR(10, 4)<<" ways";

    return 0;
}