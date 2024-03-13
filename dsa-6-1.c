#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;
void push(int value)
{
    struct stack *mm;
    mm = (struct stack *)malloc(sizeof(struct stack));
    mm->data = value;
    if (top == NULL)
    {
        mm->next = NULL;
    }
    else
    {
        mm->next = top;
    }
    top = mm;
    printf("Node is inserted\n");
}
int pop()
{
    if (top == NULL)
    {
        printf("Node cannot be deleted\n");
        printf("Stack Underflow");
    }
    else
    {
        struct stack *t = top;
        int tmp_data = top->data;
        top = top->next;
        free(t);
        return tmp_data;
    }
}

void display()
{
    if (top == NULL)
    {
        printf("No stack is created, Stack underflow");
    }
    else
    {
        printf("The stack is : \n");
        struct stack *t = top;
        while (t->next != NULL)
        {
            printf("%d\n", t->data);
            t = t->next;
        }
        printf("%d\nNULL\n\n", t->data);
    }
}
int main()
{
    int c, v;
    printf("Stack with Linked list\n");
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter any choice\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &v);
            push(v);
            break;
        case 2:
            printf("poped value is: %d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Enter a valid choice 1 to 4");
            break;
        }
    }
}