// Queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct TreeNode;

struct Queue
{
    int size;
    int front;
    int Rear;
    TreeNode **A;
};

void create(struct Queue *Q, int size)
{
    Q->size = size;
    Q->front = Q->Rear = -1;
    Q->A = new TreeNode *[Q->size];
}

// Insertion()
void enqueue(struct Queue *q, TreeNode *x)
{
    if (q->Rear == q->size - 1)
        cout << "queue is full\n";
    else
    {
        q->Rear++;
        q->A[q->Rear] = x;
    }
}

// Deletion()
TreeNode *dequeue(struct Queue *q)
{
    TreeNode *x = NULL;

    if (q->front == q->Rear)
        cout << "queue is empty\n";
    else
    {
        q->front++;
        x = q->A[q->front];
    }
    return x;
}

// isEmpty()
int isEmpty(struct Queue q)
{
    return q.front == q.Rear;
}

#endif // QUEUE_H