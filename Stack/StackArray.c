#include<stdio.h>
void push(int *stack,int *top,int size)
{
    int e;
    if(*top==size-1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter element you want to push\n");
        scanf("%d",&e);
        stack[++(*top)]=e;
    }

}
void pop(int *stack,int *top)
{
    if(*top==-1)
    {
        printf("Underflow\n");
        return;
    }
    else
        printf("Deleting item:%d\n",stack[*top]);
        *top=*top-1;
    
}
void peep(int *stack,int top)
{
    if(top==-1)
    printf("Stack Empty\n");
    else
    {
        printf("Top item:%d\n",stack[top]);
    }
}
void display(int *stack,int top)
{
    printf("The Stack is :\n");
    for(int i=0;i<=top;i++)
    printf("%d  ",stack[i]);
    printf("\n");
}
void main()
{
    int size,top=-1,i;
    printf("Enter the size of the stack\n");
    scanf("%d",&size);
    int stack[size];
    int ch;
    printf("0.Exit\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Peep\n");
    printf("4.Display\n");
    while(ch!=0)
    {
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
            ch=0;
            break;
            case 1:
            push(stack,&top,size);
            display(stack,top);
            break;
            case 2:
            pop(stack,&top);
            display(stack,top);
            break;
            case 3:
            peep(stack,top);
            break;
            case 4:
            display(stack,top);
            break;
            default:
            printf("Wrong choice\n");
        }
    }
}
