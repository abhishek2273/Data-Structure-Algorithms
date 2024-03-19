#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int Top;
    int *s;
};

// create
void create(struct Stack *st)
{
    cout << "Enter the size of stack ";
    cin >> st->size;
    st->Top = -1;
    st->s = new int[st->size];
}

// display
void Display(struct Stack st)
{
    int i;
    cout << "Elements are : ";
    for (i = st.Top; i >= 0; i--)
        printf("%d ", st.s[i]);
    cout << endl;
}

// Push (insert)
void push(struct Stack *st, int x)
{
    if (st->Top == st->size - 1)
        cout << "Stack Overflow\n";
    else
    {
        st->Top++;
        st->s[st->Top] = x;
    }
}

// pop (delete)
int pop(struct Stack *s)
{
    int x = -1;
    if (s->Top == -1)
        cout << "Stack Underflow\n";
    else
    {
        x = s->s[s->Top];
        s->Top--;
    }
    return x;
}

// Peek (search)
int peek(struct Stack st, int pos)
{
    int x = -1;
    if (st.Top - pos + 1 < 0)
        cout << "Invalid position\n";
    else
        x = st.s[st.Top - pos + 1];
    return x;
}

// stackTop
int stackTop(struct Stack st)
{
    if (st.Top == -1)
        return -1;
    else
        return st.s[st.Top];
}

// stack empty()
int isEmpty(struct Stack st)
{
    if (st.Top == -1)
        return -1;
    else
        return 0;
}

// is stack full
int isFull(struct Stack st)
{
    if (st.Top = st.size - 1)
        return 1;
    else
        return 0;
}
int main()
{
    struct Stack st;
    create(&st);

    push(&st, 2);
    push(&st, 5);
    push(&st, 589);

    printf("pop : %d\n", pop(&st));
    printf("peek : %d\n", peek(st,2));

    Display(st);

    return 0;
}