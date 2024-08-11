// Queue.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct TreeNode;

struct Stack
{
    int size;
    int Top;
    TreeNode **S;
};

// create()
void StackCreate(struct Stack *st, int size)
{
    st->size = size;
    st->Top = -1;
    st->S = new TreeNode *[st->size];
}

// Push (insert)
void push(struct Stack *st, TreeNode *x)
{
    if (st->Top == st->size - 1)
        cout << "Stack Overflow\n";
    else
    {
        st->Top++;
        st->S[st->Top] = x;
    }
}

// pop (delete)
TreeNode *pop(struct Stack *st)
{
    TreeNode *x = NULL;
    if (st->Top == -1)
        cout << "Stack Underflow\n";
    else
    {
        x = st->S[st->Top];
        st->Top--;
    }
    return x;
}

// Peek (search)
TreeNode *peek(struct Stack st, int pos)
{
    TreeNode *x = NULL;
    if (st.Top - pos + 1 < 0)
        cout << "Invalid position\n";
    else
        x = st.S[st.Top - pos + 1];
    return x;
}

// stackTop()
TreeNode *stackTop(struct Stack st)
{
    if (st.Top == -1)
        return nullptr;
    else
        return st.S[st.Top];
}

// stack empty()
int isEmptyStack(struct Stack st)
{
    if (st.Top == -1)
        return -1;
    else
        return 0;
}

// is stack full()
int isFullStack(struct Stack st)
{
    if (st.Top == st.size - 1)
        return 1;
    else
        return 0;
}

#endif // STACK_H
