#include <bits/stdc++.h>
using namespace std;

#include "Queue.h"

struct TreeNode
{
    struct TreeNode *lchild;
    int data;
    struct TreeNode *rchild;
} *root = NULL;

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

// Recursive function of PRE-POST-Order
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
    printf("\nPre Order ");
    Preorder(root);
    printf("\nPost Order ");
    Postorder(root);
    cout << "\nInorder ";
    Inorder(root);

    return 0;
}

/*
OUTPUT: Using Queue.h (Recursive traversal)
Enter root value 10
eneter left child of 10 20
eneter right child of 10 30
eneter left child of 20 -1
eneter right child of 20 -1
eneter left child of 30 -1
eneter right child of 30 -1

Pre Order 10 20 30        
Post Order 20 30 10       
Inorder 20 10 30 

*/