#include <iostream>
using namespace std;

int sumOfNaturalNumber(int n)
{
    if (n == 0)
    {
        return 0;
    }
    // return (n*(n+1)/2);
    return sumOfNaturalNumber(n - 1) + n;
}

int Factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return Factorial(n - 1) * n;
}

int powerOfaNumber(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    // return powerOfaNumber(m, n - 1) * m;
    if (n % 2 == 0)
    {
        return powerOfaNumber(m * m, n / 2);
    }
    return m * powerOfaNumber(m * m, (n - 1) / 2);
}

int main()
{
    int x = 4;
    int pn = 2;
    int pp = 9;
    cout << "Sum of Natural number " << x << " : " << sumOfNaturalNumber(x);
    cout << "\nFactorial of " << x << " : " << Factorial(x);
    cout << "\nPower of " << pn << "^" << pp << ": " << powerOfaNumber(pn, pp);
    return 0;
}
