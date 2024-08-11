/*
1.) In normal terms, Encapsulation is defined as wrapping up data and information under a single unit. In Object-Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulate them. Consider a real-life example of encapsulation, in a company, there are different sections like the accounts section, finance section, sales section, etc. The finance section handles all the financial transactions and keeps records of all the data related to finance. Similarly, the sales section handles all the sales-related activities and keeps records of all the sales. Now there may arise a situation when for some reason an official from the finance section needs all the data about sales in a particular month. In this case, he is not allowed to directly access the data of the sales section. He will first have to contact some other officer in the sales section and then request him to give the particular data. This is what encapsulation is. Here the data of the sales section and the employees that can manipulate them are wrapped under a single name “sales section”.


2.) Encapsulation is a concept in object-oriented programming where you bundle the data (attributes) and the methods (functions) that operate on the data into a single unit, called an object. It also involves restricting direct access to some of an object's components, which means that the object's internal state cannot be directly accessed from outside; instead, it's accessed through well-defined interfaces (methods).

In simple terms, think of encapsulation as a protective wrapper around your data. You interact with the data only through the methods provided, ensuring that the data is used in a controlled and intended way. This helps in maintaining the integrity and security of the data.

    */

// -------------------------------------------------

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using std::string;

// <k

class Employee
{
private:
    string Name;
    string Company;
    int Age;

public:
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }

    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }

    int setAge(int age)
    {
        if (age > 18)
            Age = age;
    }
    int getAge()
    {
        return Age;
    }

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
    Employee employee2 = Employee("A", "B", 23);

    employee1.IntroduceYourself();
    employee2.IntroduceYourself();

    employee1.setAge(9);
    cout << employee1.getName()
         << " is " << employee1.getAge()
         << " year old";

    return 0;
}
