// Combination Formula(nCr) = n!/r!(n-r)!

#include <iostream>
using namespace std;

// Method 1
int factNCR(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return factNCR(n - 1) * n;
}

int nCR(int n, int r)
{
    int num, den;
    num = factNCR(n);
    den = factNCR(r) * factNCR(n - r);

    return (num / den);
}

// Method 2
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
    cout << "NCR : " << NCR(10, 4) << " ways";
    cout << "\nnCr : " << nCR(10, 4) << " way";

    return 0;
}