/*
The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. A person at the same time can have different characteristics. A man at the same time is a father, a husband, and an employee. So the same person possesses different behavior in different situations. This is called polymorphism. An operation may exhibit different behaviors in different instances. The behavior depends upon the types of data used in the operation. C++ supports operator overloading and function overloading.

    Operator Overloading: The process of making an operator exhibit different behaviors in different instances is known as operator overloading.
    Function Overloading: Function overloading is using a single function name to perform different types of tasks. Polymorphism is extensively used in implementing inheritance.

 For example, imagine a function draw() that can be used to draw different shapes. If you have classes Circle, Square, and Triangle, each with its own implementation of the draw() method, you can call draw() on an object, and it will execute the correct method based on the object's actual class. This allows for flexible and dynamic code that can work with objects of different types in a uniform way.

// The most common use of polymorphism is when a parent class reference is used to refer to a child class object.
*/

//----------------------------------------------------------

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
    string Company;
    int Age;

protected:
    string Name;

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

    virtual void Work()
    {
        cout << Name << " is checing emails, twitter\n";
    }
};

class Developer : public Employee
{
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string fpl)
        : Employee(name, company, age)
    {
        FavProgrammingLanguage = fpl;
    }

    void FixBugs()
    {
        // cout << getName() << " fixed bug using " << " python\n";
        cout << Name << " fixed bug using " << FavProgrammingLanguage << "\n";
    }

    void Work()
    {
        cout << Name << " is developing software by using " << FavProgrammingLanguage << "\n ";
    }
};

class Teacher : public Employee
{
public:
    string Subject;
    void PreparedLesson()
    {
        cout << Name << " is preparing " << Subject << " lesson\n";
    }

    Teacher(string name, string company, int age, string sub)
        : Employee(name, company, age)
    {
        Subject = sub;
    }

    void Work()
    {
        cout << Name << " is teaching " << Subject << "\n";
    }
};

int main()
{
    Developer dev = Developer("Abhi", "Mumbai", 22, "python");
    Teacher teacher = Teacher("Elon", "roole", 65, "science");

    // Base class  =  Derive class(hold ref.)

    Employee *e1 = &dev;
    Employee *e2 = &teacher;

    // run without virtual keyword in employee work function
    e1->Work();
    e2->Work();

    return 0;
}
