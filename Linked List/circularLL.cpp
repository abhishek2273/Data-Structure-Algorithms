#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = new Node();
    head->data = A[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
// Display
void RDisplay(struct Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        RDisplay(p->next);
    }
    flag = 0;
}

void Display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

// Finding lenght of Circular Linked list
int length(struct Node *l)
{
    int count = 0;
    do
    {
        count++;
        l = l->next;
    } while (l != head);

    return count;
}

// Insert
void Insert(struct Node *p, int pos, int x)
{
    struct Node *t;
    int i;
    if (pos < 0 || pos > length(p))
    {
        return;
    }

    if (pos == 1)
    {
        t = new Node();
        t->data = x;

        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }

    else
    {
        for (i = 1; i < pos - 1; i++)
            p = p->next;
        t = new Node();
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

// Delete function
int Delete(struct Node *p, int pos)
{
    struct Node *q;
    int x, i;
    if (pos < 0 || pos > length(p))
        return -1;

    if (pos == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;

        if (p == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }

    else
    {
        for (i = 0; i < pos - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }

    return x;
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    int size = sizeof(A) / sizeof(int);

    create(A, size);
    // cout << "length is " << length(head);

    // Insert(head, 4, 100);
    cout << "Del " << Delete(head, 2) << endl;
    RDisplay(head);
    return 0;
}