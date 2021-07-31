#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void SelectionSort(int *ar,int n)
{
    int min,i,j;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(ar[min]>ar[j])
            min=j;
        }
        swap(&ar[i],&ar[min]);
    }
}
void BubbleSort(int *ar,int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(ar[j]>ar[j+1])
            {
                swap(&ar[j],&ar[j+1]);
            }
        }
    }
}
void InsertionSort(int *a,int n)
{
    int i,j,ele;
    for(i=1;i<n;i++)
    {
        ele=a[i];
        j=i-1;
        while(j>=0 && a[j]>ele)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = ele;
    }
}
int partition(int a[],int l,int h)
{
    int pivot,i,j,t;
    pivot=a[l];
    i=l;
    j=h;
    
    do
    {
        do
            i++;           
        while(a[i]<pivot&&i<=h);
        
        do
            j--;
        while(pivot<a[j]);
        
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=pivot;
    
    return(j);
}
void QuickSort(int *a,int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        QuickSort(a,l,j-1);
        QuickSort(a,j+1,h);
    }
}

void get(int *ar,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter element- %d\n",i+1);
        scanf("%d",&ar[i]);
    }
}
void print(int *ar,int n)
{
    int i;
    printf("The elements of the array are\n");
    for(i=0;i<n;i++)
    {
        printf("%d  ",ar[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    int ch;
    printf("\nEnter size of the array\n");
    scanf("%d",&n);
    int ar[n];
    printf("0.Exit\n");
    printf("1.Enter elements of the array\n");
    printf("2.Display the array elements\n");
    printf("3.Sort the array using Selection Sort Algorithm\n");
    printf("4.Sort the array using Bubble Sort Algorithm\n");
    printf("5.Sort the array using Insertion Sort Algorithm\n");
    printf("6.Sort the array using Quick Sort Algorithm\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
            exit(0);
            case 1:
            get(ar,n);
            break;
            case 2:
            print(ar,n);
            break;
            case 3:
            SelectionSort(ar,n);
            break;
            case 4:
            BubbleSort(ar,n);
            break;
            case 5:
            InsertionSort(ar,n);
            break;
            case 6:
            QuickSort(ar,0,n);
            break;
            default:
            printf("Wrong Choice... Please Try Again\n");
        }
    }
}
