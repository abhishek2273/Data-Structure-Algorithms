 /* Object-oriented programming – As the name suggests uses objects in programming. Object-oriented programming aims to implement real-world entities like inheritance, hiding, polymorphism, etc. in programming. The main aim of OOP is to bind together the data and the functions that operate on them so that no other part of the code can access this data except that function.

There are some basic concepts that act as the building blocks of OOPs i.e.

    Class
    Objects
    Encapsulation
    Abstraction
    Polymorphism
    Inheritance
    Dynamic Binding
    Message Passing
*/ 

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using std::string;

// <k

class Employee
{
public:
    string Name;
    string Company;
    int Age;

    // Function Invoke
    void IntroduceYourself()
    {
        cout << "Name : " << Name << "\n";
        cout << "Company : " << Company << "\n";
        cout << "Age : " << Age << "\n";
    }

    // Employee Constructor
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    Employee employee1 = Employee("alien", "yt", 25);

    // employee1.Name = "Alien";
    // employee1.Company = "YT";
    // employee1.Age = 90;

    Employee employee2 = Employee("A", "B", 23);

    employee1.IntroduceYourself();
    employee2.IntroduceYourself();

    return 0;
}
