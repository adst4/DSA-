#include<stdio.h>
#include<stdlib.h>
struct node
{
    int vertex;
    struct node *next;
};
typedef struct node NODE;
NODE *list[10];
void createlist(int m[][10],int n)
{
    int i,j;
    NODE *temp,*newnode;
    for(i=0;i<n;i++)
    {
        list[i]=NULL;
        for(j=0;j<n;j++)
        {
            if(m[i][j]==1)
            {
                newnode=(NODE*)malloc(sizeof(NODE));
                newnode->vertex=j+1;
                newnode->next=NULL;
                if(list[i]==NULL)
                {
                    list[i]=temp=newnode;
                }
                else
                {
                    temp->next=newnode;
                    temp=newnode;
                }
            }
        }
    }

}

void display(int n)
{
    NODE *temp;
    int i;
    printf("\nAdjancy List Is : ");
    for(i=0;i<n;i++)
    {
        printf("\nv%d->",i+1);
        temp=list[i];
        while(temp)
        {
            printf("v%d->",temp->vertex);
            temp=temp->next;
        }
        printf("NULL");
    }
}

void main()
{
    int m[10][10],n,e;
    int i,j;
    int s,d;
    printf("How Many Vertices : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            m[i][j]=0;

    printf("How Many Edges : ");
    scanf("%d",&e);
    for(i=0;i<e;i++)
    {
        printf("Enter The Edge Source And End : ");
        scanf("%d%d",&s,&d);
        m[s-1][d-1]+=1;
    }

    printf("Adajancacy Matrix Is : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }

    createlist(m,n);
    display(n);
}
