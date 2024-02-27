#include <iostream>
using namespace std;

int fibLoop(int n)
{
    int t0 = 0;
    int t1 = 1;
    int s, i;

    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}

int main()
{
    int x = 10;
    cout << "Fibonacci (loop) at no " << x << " is : " << fibLoop(x);
    cout << "\nFibonacci at no " << x << " is : " << fib(x);
    return 0;
}