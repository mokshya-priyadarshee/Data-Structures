#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void insert()
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter data for the new node\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(front==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
        rear->next=front;
    }
    
}
void delete()
{
    int d;
    if(front==NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Deleted Element: %d\n",front->data);
        front=front->next;
        rear->next=front;
    }
    
}
void display()
{
    struct node *temp=front;
    printf("The Queue elements are:\n");
    while(temp->next!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
     printf("%d",temp->data);
}
int main()
{
    int ch;
    printf("0.Exit\n");
    printf("1.Insert into Queue\n");
    printf("2.Delete into Queue\n");
    printf("3.Display Queue\n");
    printf("Queue will be displayed after each operation\n");
    while(1)
    {
        printf("\nEnter you choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
            exit(0);
            break;
            case 1:
            insert();
            display();
            break;
            case 2:
            delete();
            display();
            break;
            default:
            printf("Wrong Choice\n");
        }
    }
}