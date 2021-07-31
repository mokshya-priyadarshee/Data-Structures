#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *next;
}*start=NULL;
void create()
{
	struct node *temp,*ptr;
	int ch=1;
	while(ch==1)
	{
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data for the node\n");
	scanf("%d",&temp->info);//Use ampersand compulsory
	temp->next=NULL;
	if(temp==NULL)
	printf("Memory Full\n");
	else
	{
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=temp;

		}
	}
	printf("Do u want more nodes(1/0)\n");
	scanf("%d",&ch);
	}
	
}
void insertbeg()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data for new node\n");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(start==NULL)
	start=temp;
	else
	{
		temp->next=start;
		start=temp;
	}
}
void insertend()
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *ptr=start;
	printf("Enter Data for new node :");
	scanf("%d",&temp->info);
	temp->next=NULL;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=temp;
}
void insertpos(int pos)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *ptr=start;
	int i=1;
	printf("Enter Data for new node\n");
	scanf("%d",&temp->info);//
	temp->next=NULL;
	while(i<pos-1)
	{
		ptr=ptr->next;
		i++;
	}
	temp->next=ptr->next;
	ptr->next=temp;
}
void afternode(int pos)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *ptr=start;
	int i=1;
	printf("Enter Data for new node\n");
	scanf("%d",&temp->info);//
	temp->next=NULL;
	while(i<pos)
	{
		ptr=ptr->next;
		i++;
	}
	temp->next=ptr->next;
	ptr->next=temp;
}
void display()
{
	struct node *ptr=start;
	printf("The values of linked list are :\n");
	while(ptr!=NULL)//
	{
		printf("%d ",ptr->info);//
		ptr=ptr->next;
	}
	printf("\n");
}
void deletefirst()
{
	struct node *ptr;
	ptr=start;
	start=start->next;
	printf("The deleted data is %d",ptr->info);
	free(ptr);
}
void deleteend()
{
	struct node *ptr,*prev;
	ptr=start;
	while(ptr->next!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
	}
	prev->next=NULL;
	printf("The deleted element is %d",ptr->info);
	free(ptr);
}
void length()
{
	struct node *ptr;
	ptr=start;
	int l=1;
	if(start==NULL)
	printf("Length of the list: 0\n");
	else
	{
		while(ptr->next!=NULL)
		{
			l++;
			ptr=ptr->next;
		}
		printf("Length of the list: %d\n",l);
	}
}
void deleteall()
{
	struct node *ptr=start,*d;
	while(ptr!=NULL)
	{
		d=ptr;
		ptr=ptr->next;
		printf("Deleting node with value %d\n",d->info);
		free(d);
	}
}
void reverse()
{
	struct node *ptr,*prv,*nxt;
	if(start==NULL)
	{
		printf("Linked List Empty");
		return;
	}
	else
	{
		ptr=start->next;
		prv=start;
		nxt=start->next->next;
		ptr->next=prv;
		prv->next=NULL;
		prv=ptr;
		ptr=nxt;
		while(nxt->next!=NULL)
		{
			ptr->next=prv;
			prv=ptr;
			ptr=nxt;
			nxt=nxt->next;
		}
		ptr->next=prv;
		start=nxt;
	}
	
}
/*struct node * linearsearch(int num)
{
	struct node *ptr=start;
	int c=1; 
	if(start==NULL)
	{
		printf("Linked List is empty, Try again\n");
	}
	else
	{
		while(ptr->next!=NULL)
		{
			c++;
			if(ptr->info==num)
			{
				printf("Node Found\n");
				printf("Node Position: %d",c);
				return ptr;
			}
			ptr=ptr->next;
		}
	}
	

}*/
int main()
{
	int ch=1,n;
	struct node *ptr;
	printf("1.Create Linked List\n");
	printf("2.Insert node at beginning\n");
	printf("3.Insert node at a position\n");
	printf("4.Insert node at end\n");
	printf("5.Insert after a node\n");
	printf("6.Delete first node\n");
	printf("7.Delete last node\n");
	printf("8.Length of the linked list\n");
	printf("9.Delete all nodes and end\n");
	printf("11.Reverse Linked List\n");
	printf("0.End\n");
	printf("Linked list will be displayed after each operation\n");
	while(ch!=0)
	{
	printf("Enter your choice\n");
	fflush(stdin);
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		create();
		display();
		break;
	case 2:
		insertbeg();
		display();
		break;
	case 3:
		printf("Enter the position at which node is to be inserted\n");
		int p;
		scanf("%d",&p);
		insertpos(p);
		display();
		break;
	case 4:
		insertend();
		display();
		break;
	case 5:
		printf("Enter the position at which node is to be inserted\n");
		int pos;
		scanf("%d",&pos);
		afternode(pos);
		display();
		break;
	case 6:
		deletefirst();
		display();
		break;
	case 7:
		deleteend();
		display();
		break;
	case 8:
		length();
		break;
	case 9:
		deleteall();
		printf("All nodes successfully deleted\n");
		printf("Terminating Program...\n");
		exit(0);
		break;
	/*case 10:
		printf("Enter element to be searched\n");
		scanf("%d",n);
		ptr=linearsearch(n);
	*/
	case 11:
	reverse();
	display();
	break;
	case 0:
		exit(0);
		break;
	default:
		printf("Wrong choice\n");
	}
  }
}
