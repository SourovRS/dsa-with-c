#include<stdio.h>
int stack[100],choice,n,top,x,i;
void display(void);
void push(void);
void pop(void);
int main()
{

    top=-1;
    printf("\n Size of STACK[not more than 100]:");
    scanf("%d",&n);
    printf("\n\tSTACK Operations by using array:\n");
    printf("\n\t 1.Display\n\t 2.Push\n\t 3.Pop\n\t 4.Exit");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                display();
                break;
            }
            case 2:
            {
                push();
                break;
            }
            case 3:
            {
                pop();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
