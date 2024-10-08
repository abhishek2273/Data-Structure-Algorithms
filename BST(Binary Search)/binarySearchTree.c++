// Binary Search Tree (BST)

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

// New node Insert in BST
void Insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL)
    {
        p = new Node();
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }

    p = new Node();
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

// Inorder recursive function
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

// BST Search function
struct Node *Search(int key)
{
    struct Node *t = root;

    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

//  Main Function
int main()
{
    struct Node *temp;

    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

    cout << "Inorder: ";
    Inorder(root);
    cout << "\nPrerder: ";
    Preorder(root);
    cout << "\nPostorder: ";
    Postorder(root);

    temp = Search(20);
    if (temp != NULL)
        cout << "\nelement found " << temp->data;
    else
        cout << "\nelement not found";

    return 0;
}
