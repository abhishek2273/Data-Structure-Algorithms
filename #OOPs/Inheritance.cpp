/*
Inheritance is a principle in object-oriented programming where a new class, known as a child or subclass, is created based on an existing class, known as a parent or superclass. The child class inherits attributes and methods from the parent class, allowing for code reuse and the creation of hierarchical relationships between classes.

In simple terms, inheritance is like a family tree. Just as children inherit characteristics from their parents, a subclass inherits properties and behaviors from its superclass. For example, if you have a class Vehicle with attributes like speed and color and methods like move(), you can create a subclass Car that inherits these attributes and methods. The Car class can also have additional attributes and methods specific to cars, like number_of_doors and honk(). This way, Car gets all the features of Vehicle without having to rewrite the common code.

Inheritance private by default
*/

//------------------------------------------

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
        cout << Name << " fixed bug using " << " python\n";
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
};

int main()
{
    Employee employee1 = Employee("alien", "yt", 25);

    Developer dev = Developer("Abhi", "Mumbai", 22, "python");

    // dev.FixBugs();
    // dev.AskForPromotion();

    Teacher teacher = Teacher("Elon", "roole", 65, "science");
    teacher.PreparedLesson();
    teacher.AskForPromotion();

    return 0;
}
