#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL,*top=NULL;
void push()
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(temp)
    {
    temp->next=NULL;
    printf("Enter data for node\n");
    scanf("%d",&temp->info);
    if(start==NULL)
    {
        printf(".\n");
        start=temp;
        top=temp;
    }
    else
    {
        top->next=temp;
        top=temp;
    }
    }
    else 
    printf("Memory Allocation Failed");
}
void pop()
{
    printf("Deleting data :%d",top->info);
    struct node *ptr=start,*t=top;
    while(ptr->next!=top)
    {
        ptr=ptr->next;
    }
    ptr->next=NULL;
    free(t);
    top=ptr;
}
void display()
{
    printf("The elements of the stack are:\n");
    struct node *ptr=start;
    while(ptr->next!=NULL)
    {
        printf("%d  ",ptr->info);
        ptr=ptr->next;
    }
}
void peep()
{
    if(top=NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Top item: %d",&top->info);
    }
    
}
void main()
{
    int ch=1;
    printf("-------------------------Stack Using Linked List---------------------------------------------\n");
    printf("0.Exit\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Peep\n");
    printf("4.Display\n");
    printf("Stack would be displayed after each operation\n");
    while(ch!=0)
    {
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
            exit(0);
            break;
            case 1:
            push();
            display();
            break;
            case 2:
            pop();
            display();
            break;
            case 3:
            peep();
            break;
            case 4:
            display();
            break;
        }
    }
}