/*Suppose one stack is given, where the elements are stored in sorted order with
their number of occurrences i.e each stack element contains two part: element and
the number of time it is occurring . Using the basic stack push() and pop()
operations, implement the following insert() and delete() functions. a. Insert():- insert one new element in the stack using the push() or/and pop()
operation(s) such that if the element exist then it will just increase the
number of occurrences or if element doesn’t exist then it will insert the
element with its occurrence as 1. After insertion of the element the stack
must be sorted. b. Delete():- delete the existing element from the stack using the push() or/and
pop() operation(s) such that if the element exist then it will just decrease the
number of occurrences or if element doesn’t exist then it will give the
underflow message.*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int occur;
    struct node *next;
}*start=NULL,*top=NULL;
void push()
{
    printf("Enter the data for the node\n");
    struct node *temp,*ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(ptr==NULL)
    {
        ptr=temp;
        start=temp;
        top=temp;
        temp->occur=1;
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->data==temp->data)
            {
                (ptr->occur)++;
                free(temp);
                return;
            }
            ptr=ptr->next;
            printf("1\n");
        }
        top->next=temp;
        temp->occur=1;
        top=temp;
    }
    
}
void pop()
{
    struct node *ptr=start,*prev;
    if(top==NULL)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        (top->occur)--;
        if(top->occur==0)
        {
            if(top==start && top->occur==1)
            {
                top=NULL;
                start=NULL;
                return;
            }
            while(ptr->next!=NULL)
            {
                prev=ptr;
                ptr=ptr->next;
            }
            prev->next=NULL;
            top=prev;
            free(ptr);
        }
    }
}
void display()
{
    struct node *ptr=start;
    if(ptr==NULL)
    {
        printf("The stack is empty\n");
        return;
    }
    while(ptr!=NULL)
    {
        printf("Element:%d      Occurance:%d\n",ptr->data,ptr->occur);
        ptr=ptr->next;
    }
    
}
int main()
{
    printf("------------Stack with occurance---------------\n");
    printf("0.Exit\n");
    printf("1.Insert into Stack\n");
    printf("2.Delete from stack\n");
    printf("3.Display the stack\n");
    int ch;
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
            exit(0);
            case 1:
            push();
            display();
            break;
            case 2:
            pop();
            display();
            break;
            default:
            printf("Wrong Choice Please try again\n");
        }
    }
}