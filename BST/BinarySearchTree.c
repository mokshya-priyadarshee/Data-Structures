#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;
node * create()
{
    node *temp=(node *)malloc(sizeof(node));
    printf("Enter data for the node\n");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insert(node *root,node *ptr)
{
    /*if(root==NULL)
    {
        root=ptr;
    }*/
    if(ptr->data>root->data)
    {
        if(root->right==NULL)
            root->right=ptr;
        else
            insert(root->right,ptr);
    }
    else if(ptr->data<root->data)
    {
        if(root->left==NULL)
            root->left=ptr;
        else
        insert(root->left,ptr);
    }
    
}
void infix(node *root)
{
    if(root!=NULL)
    {
        infix(root->left);
        printf("%d  ",root->data);
        infix(root->right);
    }
}
void postfix(node *root)
{
    if(root!=NULL)
    {
        postfix(root->left);
        postfix(root->right);
        printf("%d  ",root->data);
    }
}
void prefix(node *root)
{
    if(root!=NULL)
    {
        printf("%d  ",root->data);
        infix(root->left);
        infix(root->right);
    }
}
void search(node * root,int n)
{
    if(root==NULL)
    {
        printf("Search Unsuccessful\n");
        return;
    }
    else if(root->data==n)
    {
        printf("Element searched for is present in binary tree\n");
        return;
    }
    else if(root->data>n)
        search(root->left,n);
    else if(root->data<n)
        search(root->right,n);
}
node * delete(node *root,int n)
{
    if(root->data>n)
    {
        delete(root->left,n);
    }
    else if(root->data<n)
    {
        delete(root->right,n);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
        }
        else if(root->left==NULL)
        {
            root
        }
    }
    
}
void main()
{
    node *ptr,*root=NULL;
    char ch='y';
    int c,n;
    printf("1.Insert a node into the binary search tree\n");
    printf("2.Delete an element from binary search tree\n");
    printf("3.Search an element in a binary search tree\n");
    printf("4.Print the elements of the tree in Infix Order\n");
    printf("5.Print the elements of the tree in Prefix Order\n");
    printf("6.Print the elements of the tree in Postfix Order\n");
    printf("0.Exit from the Program\n");
    while(1)
    {
        printf("Enter your Choice\n");
        scanf("%d",&c);
        switch(c)
        {
            case 0:
            exit(1);
            case 1:
            while(ch=='y'||ch=='Y')
            {
                if(root==NULL)
                {
                    root=create();
                }
                else
                {
                    ptr=create();
                    insert(root,ptr);
                }
                printf("Do you want to insert more nodes?\n");
                fflush(stdin);
                scanf("%c",&ch);
            }
            break;
            case 3:
            printf("Enter the element to be searched\n");
            scanf("%d",&n);
            search(root,n);
            break;
            case 4:
            printf("\nInfix Order of the Tree:");
            infix(root);
            printf("\n");
            break;
            case 5:
            printf("\nPrefix Order of the Tree:");
            prefix(root);
            printf("\n");
            break;
            case 6:
            printf("\nPostfix Order of the Tree:\n");
            postfix(root);
            printf("\n");
            break;
            default:
            printf("You have entered a wrong choice try again...\n");
        }
    }
}
