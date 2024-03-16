#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first;

// Create
void create(int A[], int n)
{
    struct Node *t, *last;
    first = new Node();
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Display
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    cout << endl;
}

// count
int length(struct Node *p)
{
    int count = 0;
    while (p != 0)
    {
        count++;
        p = p->next;
    }
    return count;
}

// Insert
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > length(p))
        return;

    if (index == 0)
    {
        t = new Node();
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }

    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node();
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int main()
{
    int A[] = {2, 3, 5, 8, 10};
    int s = sizeof(A) / sizeof(int);

    create(A, s);

    // cout << "length : " << length(first) << endl;

    // Insert(first, 2, 25);
    Display(first);

    return 0;
}