/* Abstraction is a fundamental concept in object-oriented programming that involves simplifying complex systems by modeling classes based on the essential characteristics that are relevant to the context, while ignoring the irrelevant details. It focuses on the "what" rather than the "how. */

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using std::string;

// < k

class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee
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

    void AskForPromotion()
    {
        if (Age > 35)
            cout << Name << " got promoted.\n";
        else
            cout << Name << " sorry No promotion for you.\n";
    }
};

int main()
{
    Employee employee1 = Employee("alien", "yt", 25);
    Employee employee2 = Employee("jaaadu", "pt", 40);

    employee1.AskForPromotion();
    employee2.AskForPromotion();

    return 0;
}
