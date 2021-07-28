#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
}*start=NULL;
void create()
{
    int ch=1;
    struct node *ptr,*prev;
    start=(struct node *)malloc(sizeof(struct node));
    printf("Enter data for the node\n");
    scanf("%d",&start->info);
    start->next=NULL;
    printf("Do you want more(1/0)\n");
    scanf("%d",&ch);
    prev=start;
    while(ch==1)
    {
        ptr=(struct node *)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&ptr->info);
        ptr->next=NULL;
        prev->next=ptr;
        prev=ptr;
        printf("Do you want more\n");
        scanf("%d",&ch);
    }
    ptr->next=start;
}
void insertbeg()
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *temp=start;
    printf("Enter data for the node\n");
    scanf("%d",&ptr->info);
    ptr->next=start;
    do
    {
        temp=temp->next;
    } while (temp->next!=start);
    start=ptr;
    temp->next=ptr;
    
}
void insertend()
{
    struct node *temp,*ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter data for the node\n");
    scanf("%d",&ptr->info);
    temp=start;
    do
    {
        temp=temp->next;
    } while (temp->next!=start);
    temp->next=ptr;
    ptr->next=start;
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
    cur=start;
    while(c<pos)
    {
        prv=cur;
        cur=cur->next;
        c++;
    }
    prv->next=ptr;
    ptr->next=cur;
}
void deletebeg()
{
    struct node *f=start,*end=start,*ptr=start;
    do
    {
        end=end->next;
    } while (end->next!=start);
    start=start->next;
    end->next=start;
    free(f);
    
}
void deletepos()
{
    struct node *ptr=start,*prv;
    int c=0,pos;
    printf("Enter position of element to be deleted\n");
    scanf("%d",&pos);
    while(c<pos-1)
    {
        prv=ptr;
        ptr=ptr->next;
        c++;
    }
    prv->next=ptr->next;
    free(ptr);
}
void deleteend()
{
    struct node *prv,*ptr=start;
    do
    {
        prv=ptr;
        ptr=ptr->next;
    } while (ptr->next!=start);
    prv->next=start;
    free(ptr);
}
void countoccurance()
{
    int c=0,n;
    printf("Enter data to be searched for counting\n");
    scanf("%d",&n);
    struct node *ptr=start;
    do
    {
    if(ptr->info==n)
    c++;
    }while(ptr->next!=start);
    printf("Number of occurence: %d",c);
}
void insertafternodeinfo()
{
    struct node *ptr,*prv,*temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter data for the node to be inserted\n");
    scanf("%d",&temp->info);
    temp->next=NULL;
    printf("Enter data for the node to searched\n");
    int n;
    scanf("%d",&n);
    ptr=start;
    while(ptr->info!=n||ptr->next==NULL)
    {
        prv=ptr;
        ptr=ptr->next;
    }
    prv=ptr;
    ptr=ptr->next;
    prv->next=temp;
    temp->next=ptr;
}
void deletenodeinfo()
{
    struct node *ptr,*prv;
    int n;
    printf("Enter data at which node is to be deleted\n");
    scanf("%d",&n);
    ptr=start;
    while(ptr->info!=n)
    {
        prv=ptr;
        ptr=ptr->next;
    }
    prv->next=ptr->next;
    free(ptr);
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
    int ch=1;
    printf("0.Exit\n");
    printf("1.Create a Circular Linked List\n");
    printf("2.Display Circular Linked List\n");
    printf("3.Insert at beginning\n");
    printf("4.Insert at end\n");
    printf("5.Insert at any position\n");
    printf("6.Delete from beginning\n");
    printf("7.Delete from end\n");
    printf("8.Delete from a postion\n");
    printf("9.Insert after a given node\n");
    printf("10.Delete a given node\n");
    printf("11.Count occurence");
    printf("Circular Linked List will be displayed after every operation\n");
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
            create();
            display();
            break;
            case 2:
            display();
            break;
            case 3:
            insertbeg();
            display();
            break;
            case 4:
            insertend();
            display();
            break;
            case 5:
            insertpos();
            display();
            break;
            case 6:
            deletebeg();
            display();
            break;
            case 7:
            deleteend();
            display();
            break; 
            case 8:
            deletepos();
            display();
            break;
            case 9:
            insertafternodeinfo();
            display();
            break;
            case 10:
            deletenodeinfo();
            display();
            break;
            case 11:
            countoccurance();
            break;
            default:
            printf("Wrong Choice. Please Try again\n");
        }
    }
}