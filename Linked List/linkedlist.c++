#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node();
    first->data = A[0]; // first node is assign here
    first->next = NULL;
    last = first;

    // rest of node assign using this loop
    for (i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Displaly function
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Recursive Display
void RDisplay(struct Node *rd)
{
    if (rd != NULL)
    {
        printf("%d ", rd->data);
        RDisplay(rd->next);
    }
}

// Count Node :
int Count(struct Node *p)
{
    int count = 0;
    while (p != 0)
    {
        count++;
        p = p->next;
    }
    return count;
}

// Add element in Node
int Add(struct Node *a)
{
    int sum = 0;
    while (a != 0)
    {
        sum = sum + a->data;
        a = a->next;
    }
    return sum;
}

// Reccursive Add element in Node
int RAdd(struct Node *a)
{
    if (a == 0)
        return 0;
    else
        return RAdd(a->next) + a->data;
}

// Maximum element of Node
void MaxMin()
{
    int Max16 = INT16_MAX;
    int Max32 = INT32_MAX;

    int Min16 = INT16_MIN;
    int Min32 = INT32_MIN;

    printf("Max16 : %d\n", Max16);
    printf("Min16 : %d\n", Min16);
    printf("Max32 : %d\n", Max32);
    printf("Min32 : %d\n", Min32);
}

int Max(struct Node *m)
{
    // max = -32768 is minimum number of 16 bit compiler
    int max = INT32_MIN;
    while (m != NULL)
    {
        if (m->data > max)
            max = m->data;
        m = m->next;
    }
    return max;
}
int Min(struct Node *m)
{
    int min = INT32_MAX;
    while (m != NULL)
    {
        if (m->data < min)
            min = m->data;
        m = m->next;
    }
    return min;
}

// Searching in Node
struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);
    // Display(first);
    // RDisplay(first);
    // cout<<Count(first);
    // cout << Add(first);
    // cout << RAdd(first);
    // MaxMin();

    // cout << "Max " << Max(first) << endl;
    // cout << "Min " << Min(first);

    struct Node *temp;
    int key = 7;
    temp = Search(first, key);
    if (temp)
        cout << key << " is found";
    else
        cout << key << " is not found";
    return 0;
}