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

// count
int Count(struct Node *p)
{
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

// Delete
int DeleteNode(struct Node *p, int pos)
{
    struct Node *q;
    int x = -1;

    if (pos < 1 || pos > Count(p))
        return x;

    if (pos == 1)
    {
        q = first;
        first = first->next;
        x = q->data;
        free(q);
        return x;
    }

    else if (pos > 0)
    {
        for (int i = 0; i < pos - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            x = p->data;
            free(p);
            return x;
        }
    }
}

// isSorted
int isSorted(struct Node *p)
{
    int x = INT16_MIN;
    p = first;
    while (p != NULL)
    {
        if (p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

// Remove Duplicate
void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (q->data != p->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

// Reverse a Linked List
void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;

    A = new int[sizeof(int) * Count(p)];

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

int main()
{
    int A[] = {2, 5, 6, 8, 20};
    // int A[] = {2, 2, 3, 8, 8, 8};
    int size = sizeof(A) / sizeof(int);

    create(A, size);
    // Insert(2, 100);
    // InsertLast(200);
    // SortInsert(7);
    // printf("delete element is %d\n", DeleteNode(first, 30));
    // printf("%d\n", isSorted(first));
    // RemoveDuplicate(first);

    Reverse1(first);
    Display(first);
    return 0;
}