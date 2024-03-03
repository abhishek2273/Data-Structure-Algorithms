#include <iostream>
void increment(int &x)
{ // "&" denotes pass by reference
    x++;
    std::cout << "Inside function: " << x << std::endl;
}
int main()
{
    int num = 5;
    increment(num); // num is passed by reference
    std::cout << "Outside function: " << num << std::endl;
    return 0;
}

/*Output:
        Inside function: 6
        Outside function: 6
*/

/*
    In call by reference, the memory address (reference) of the actual parameter is passed to the function.
    This allows the function to directly access and modify the original value of the arguments outside the function.
    This method is more memory-efficient than call by value because it avoids unnecessary copying.
    Languages like C++ provide reference types (&) or pointers (*) to achieve call by reference.
*/