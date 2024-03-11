#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

// Create
void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Insert before First
void Insert(int pos, int x)
{
    struct Node *t, *p;
    int i;
    if (pos == 0)
    {
        t = new Node();
        t->data = x;
        t->next = first;
        first = t;
    }

    else if (pos > 0)
    {
        p = first;
        for (i = 0; i < pos - 1 && p; i++)
            p = p->next;

        if (p)
        {
            t = new Node();
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

// Insert at last always
void InsertLast(int x)
{
    struct Node *t, *last;
    t = new Node();
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = last = t;
    else
    {
        last = first;
        while (last->next != NULL)
            last = last->next;

        last->next = t;
        last = t;
    }
}

// Add Element in Sorted List
void SortInsert(int x)
{
    struct Node *t, *p = first, *q = NULL;

    while (p && p->data < x)
    {
        q = p;
        p = p->next;
    }
    t = new Node();
    t->data = x;
    t->next = q->next;
    q->next = t;
}

int main()
{
    int A[] = {2, 5, 6, 8, 20};

    create(A, 5);
    // Insert(2, 100);
    // InsertLast(200);
    SortInsert(7);
    Display(first);
    return 0;
}