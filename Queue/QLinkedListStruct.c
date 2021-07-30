#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
void enqueue(NODE *front,NODE *rear)
{
    NODE *temp=(NODE *)malloc(sizeof(NODE));
    printf("Enter data for the node\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    printf("%d",front==NULL);
    if(front==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    printf("\n%d\n",front->data);
    printf("\n%d\n",rear->data);
    printf("\n%d\n",temp->data);
}
void dequeue(NODE *front,NODE *rear)
{
    NODE *temp=front;
    if(front=NULL)
    {
        printf("Underflow\n");
        return;
    }
    else if(front==rear)
    {
        front=NULL;
        rear=NULL;
        printf("Deleting element:%d",&temp->data);
        free(temp);
    }
    else
    {
        front=front->next;
        printf("Deleting element:%d\n",&temp->data);
        free(temp);
    }
}
void peek(NODE *front,NODE *rear,int e)
{
    NODE *temp=front;
    for(;temp!=NULL;temp=temp->next)
    {
        if(temp->data == e)
        break;
    }
    if(temp==NULL)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found !!");
    }
    
}
void display(NODE *front)
{
    printf("The elements of queue are:\n");
    for(NODE *ptr=front;ptr!=NULL;ptr=ptr->next)
        printf("%d",ptr->data);
}
int main()
{
    NODE *front=NULL,*rear=NULL;
    int ch,n;
    printf("0.Exit\n");
    printf("1.Insert into Queue\n");
    printf("2.Delete from Queue\n");
    printf("3.Peek(Search) in Queue\n");
    printf("4.Display the Queue\n");
    while(1)
    {
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
            exit(0);
            case 1:
            enqueue(front,rear);
            display(front);
            break;
            case 2:
            dequeue(front,rear);
            display(front);
            break;
            case 3:
            printf("Enter number to be searched\n");
            scanf("%d",&n);
            peek(front,rear,n);
            break;
            case 4:
            display(front);
            break;
            default:
            printf("Wrong Choice...Please try again...\n");
        }
    }
}