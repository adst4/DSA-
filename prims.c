#include <stdio.h>
#define INF 999

int primMST(int m[10][10],int n)
{
    int visited[n];
    int i, j;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    int numEdge = 0;
    int cost = 0;
    visited[0] = 1;

    while (numEdge < n - 1)
    {
        int min = INF;
        int x = 0;
        int y = 0;

        for (i = 0; i < n; i++)
        {
        
        	
            if (visited[i])
            {
            	
                for (j = 0; j < n; j++)
                {
                	
                
                    if (!visited[j] && m[i][j])
                    {
                    
                        if (min > m[i][j])
                        {
                        	printf("Edge : %d - %d (cost : %d)\n",i+1,j+1,m[i][j]);
                            min = m[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        visited[y] = 1;
        numEdge++;
        cost += min;
    }

    return cost;
}

int main()
{
	int i,j,cost;
	int m[10][10],n,e;
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
        printf("Enter the Cost : ");
        scanf("%d",&cost);
        m[s-1][d-1]=cost;
        m[d-1][s-1]=cost;
    }
    
    printf("Minimum Spaning Tree Is : \n");

    int mincost = primMST(m,n);
    printf("Minimum cost of the spanning tree is %d", mincost);
    return 0;
}
