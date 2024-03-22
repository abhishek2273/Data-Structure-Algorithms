#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    void push(int x);
    int pop();
    void Display();
};

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "stack is full";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int main()
{
    return 0;
}