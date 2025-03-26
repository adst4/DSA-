#include<stdio.h>
#include<stdlib.h>

void display(int dist[][10],int n)
{
    int i,j;
    printf("Adajacency Matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(dist[i][j] == 999)
                printf("%4s\t","Inf");
            else
                printf("%d\t",dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][10], int n)
{
    int i, j, k;
    int dist[10][10];
    
    // Copy the given graph into a new matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            dist[i][j] = graph[i][j];
    
    // Do the Floyd-Warshall algorithm 
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    display(dist,n);
}

int main()
{
    int graph[10][10],n,e;
    int i,j;
    int s,d,cost;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    
    // Initialize the adjacency matrix with 999 to indicate no path exists
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            graph[i][j] = 999;

    printf("Enter the number of edges: ");
    scanf("%d",&e);
    for(i=0;i<e;i++)
    {
        printf("Enter the source vertex and destination vertex of edge %d: ", i+1);
        scanf("%d %d",&s,&d);
        printf("Enter the cost: ");
        scanf("%d",&cost);
        graph[s-1][d-1] = cost;
    }

    floydWarshall(graph,n);
}

