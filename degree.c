#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m[10][10],n,e;
    int i,j;
    int s,d;
    int indegree,outdegree,v;
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

    printf("Enter The Vertex To Calculate In degree : ");
    scanf("%d",&v);
    indegree=0;
    for(i=0;i<n;i++)
    {
        indegree=indegree+m[i][v-1];
    }
    printf("Indegree Of %d Vertex Is :%d ",v,indegree);

    printf("\nEnter The Vertex To Calculate In degree : ");
    scanf("%d",&v);
    outdegree=0;
    for(i=0;i<n;i++)
    {
        outdegree=outdegree+m[v-1][i];
    }
    printf("outdegree Of %d Vertex Is :%d ",v,outdegree);
}
