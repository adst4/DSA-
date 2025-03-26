#include<stdio.h>
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

    
}
