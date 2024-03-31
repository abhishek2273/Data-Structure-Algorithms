#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int Rear;
    int *A;
};

void create(struct Queue *Q, int size)
{
    Q->size = size;
    Q->front = Q->Rear = -1;
    Q->A = new int[Q->size * sizeof(int)];
}

// Insertion
void enqueue(struct Queue *q, int x)
{
    if (q->Rear == q->size - 1)
        cout << "queue is full\n";
    else
    {
        q->Rear++;
        q->A[q->Rear] = x;
    }
}

// Deletion
int dequeuq(struct Queue *q)
{
    int x = -1;

    if (q->front == q->Rear)
        cout << "queue is empty\n";
    else
    {
        q->front++;
        x = q->A[q->front];
    }
    return x;
}

// Display
void Display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.Rear; i++)
    {
        cout << q.A[i] << " ";
    }
    cout << endl;
}

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    Display(q);

    cout << dequeuq(&q) << endl;

    Display(q);
    return 0;
}