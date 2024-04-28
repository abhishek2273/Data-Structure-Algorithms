#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct TreeNode
{
    struct TreeNode *lchild;
    int data;
    struct TreeNode *rchild;
} *root = NULL;

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

// Creating a Tree using Queue
void Treecreate()
{
    struct TreeNode *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value ");
    scanf("%d", &x);
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new TreeNode();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void Preorder(struct TreeNode *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct TreeNode *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct TreeNode *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main()
{
    Treecreate();
    Preorder(root);
    printf("\nPost Order ");
    Postorder(root);
    cout << "\nInorder ";
    Inorder(root);
    cout << "\nPostorder ";
    Postorder(root);
    return 0;
}

/*
OUTPUT:
Enter root value 10
eneter left child of 10 20
eneter right child of 10 30
eneter left child of 20 -1
eneter right child of 20 -1
eneter left child of 30 -1
eneter right child of 30 -1
10 20 30 
Post Order 20 30 10       
Inorder 20 10 30 
Postorder 20 30 10      

*/