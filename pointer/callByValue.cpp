#include <iostream>
void increment(int x)
{
    x++;
    std::cout << "Inside function: " << x << std::endl;
}
int main()
{
    int num = 5;
    increment(num); // num is passed by value
    std::cout << "Outside function: " << num << std::endl;
    return 0;
}

/*Output:
        Inside function: 6
        Outside function: 5
*/

/*  In call by value, a copy of the actual parameter's value is passed to the function.
    The function works with this copy, and any changes made to the parameters inside the function do not affect the original value of the arguments outside the function.
    This is the default behavior in many programming languages, including C and C++ for primitive data types.
    It is simple and straightforward, but can be inefficient when dealing with large data structures because of the overhead of copying.
    */