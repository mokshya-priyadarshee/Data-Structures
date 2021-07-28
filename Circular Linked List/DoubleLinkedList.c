#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start=NULL;
void create()
{
    int ch=1;
    struct node *ptr,*prv;
    start=(struct node *)malloc(sizeof(struct node));
    printf("Enter data for the node\n");
    scanf("%d",&start->info);
    start->next=NULL;
    start->prev=NULL;
    printf("Do you want more(1/0)\n");
    scanf("%d",&ch);
    prv=start;
    while(ch==1)
    {
        ptr=(struct node *)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&ptr->info);
        ptr->next=NULL;
        ptr->prev=prv;
        prv->next=ptr;
        prv=ptr;
        printf("Do you want more\n");
        scanf("%d",&ch);
    }
    ptr->next=start;
    start->prev=ptr;
}
void insertpos()
{
    struct node *cur,*prv,*ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter position at which the new node is to inserted\n");
    int pos,c=1;
    scanf("%d",&pos);
    printf("Enter the data for the node\n");
    scanf("%d",&ptr->info);
    ptr->next=NULL;
    ptr->prev=NULL;
    cur=start;
    while(c<pos)
    {
        prv=cur;
        cur=cur->next;
        c++;
    }
    prv->next=ptr;
    ptr->prev=prv;
    ptr->next=cur;
    cur->prev=ptr;
}
void deletebeg()
{
    struct node *f=start,*end=start,*ptr=start;
    do
    {
        end=end->next;
    } while (end->next!=start);
    start=start->next;
    start->prev=NULL;
    end->next=start;
    free(f);
    
}
void display()
{
    struct node *ptr;
    printf("The Linked List elements are:\n");
    ptr=start;
    do    
    {
        printf("%d  ",ptr->info);
        ptr=ptr->next;
    }while(ptr!=start);
}
int main()
{
    create();
    display();
    insertpos();
    display();
    deletebeg();
    display();
}
