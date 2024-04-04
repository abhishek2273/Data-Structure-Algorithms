#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }

    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if (rear == size - 1)
        cout << "Queue full\n";
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue ::dequeue()
{
    int x = -1;
    if (front == rear)
        cout << "Queue is empty\n";
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << flush;
        if (i < rear)
        {
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

int main()
{

    int A[] = {1, 3, 5, 7, 9};

    Queue q(sizeof(A) / sizeof(A[0]));

    // Enqueue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        q.enqueue(A[i]);
    }

    // Display
    q.display();

    // Overflow
    q.enqueue(10);

    // Dequeue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        q.dequeue();
    }

    // Underflow
    q.dequeue();

    return 0;
}