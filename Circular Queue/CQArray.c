#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node
{
    int front;
    int rear;
    int ar[MAX];
}QUEUE;
QUEUE *q;
int size;
void enqueue()
{
    int n;
    printf("Enter element to be inserted\n");
    scanf("%d",&n);
    if((q->rear==size-1 && q->front==0)||q->front==(q->rear)+1)
    {
        printf("Overflow\n");
        return;
    }
    else if(q->rear==-1)
    {
        q->front=0;
        q->rear=0;
        q->ar[q->rear]=n;
    }
    else if(q->rear== size-1)
    {
        q->rear=0;
        q->ar[q->rear]=n;
    }
    else 
    {
        q->rear++;
        q->ar[q->rear]=n;
    }
}
void dequeue()
{
    if(q->rear=-1)
    {
        printf("Underflow\n");
        return;
    }
    else if(q->rear==q->front)
    {
        printf("Deleted element:%d",q->ar[q->front]);
        q->front=-1;
        q->rear=-1;
    }
    else if(q->front=size-1)
    {
        q->front=0;
    }
    else
    {
        printf("Deleted element:%d",q->ar[q->front]);
        q->front++;
    }
}
void display()
{
    if(q->rear>q->front)
    {
        for(int i=q->front;i<=q->rear;i++)
        {
            printf("%d ",q->ar[i]);
        }
        printf("\n");
    }
    else if(q->rear<q->front)
    {
        for(int i=q->front;i<size;i++)
        printf("%d",q->ar[i]);
        for(int i=0;i<=q->rear;i++)
        printf("%d",q->ar[i]);
    }
}
int main()
{
    printf("Enter size of array\n");
    scanf("%d",&size);
    int ch;
    q->rear=-1;
    q->front=-1;
     printf("------------Circular Queue with Array--------------------------\n");
    printf("1.Insert into Queue\n");
    printf("2.Delete from Queue\n");
    printf("3.Display the Queue\n");
    while(1)
    {
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
            exit(0);
            break;
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            default:
            printf("Wrong Choice.. Try again\n");
        }
    }
}
