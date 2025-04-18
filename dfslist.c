
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int var;
    struct node *next;
} NODE;
int visited[10] = {0};

void dfs(NODE *adjlist[10], int v)
{
    visited[v] = 1;
    printf("%d\t", v);
    NODE *temp = adjlist[v];
    while (temp)
    {
        if (!visited[temp->var])
        {
            dfs(adjlist, temp->var);
        }
        temp = temp->next;
    }
}
NODE *create(int ver)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->var = ver;
    return newnode;
}
int main()
{
    int vertex, i, edges, sor, dest;
    NODE *temp;
    printf("how many vertex are there\n");
    scanf("%d", &vertex);
    NODE *adjlist[vertex];
    for (i = 1; i <= vertex; i++)
    {
        adjlist[i] = NULL;
    }
    printf("how many edges are there\n");
    scanf("%d", &edges);
    for (i = 1; i <= edges; i++)
    {
        printf("enter a source and destination of edge\n");
        scanf("%d%d", &sor, &dest);
        NODE *newnode = create(dest);
        newnode->next = adjlist[sor];
        adjlist[sor] = newnode;

        newnode = create(sor);
        newnode->next = adjlist[dest];
        adjlist[dest] = newnode;
    }
    for (i = 1; i <= vertex; i++)
    {
        temp = adjlist[i];
        printf("Vertex %d:", i);
        while (temp)
        {

            printf("%d", temp->var);
            printf("-->");
            temp = temp->next;
        }
        printf("|NULL|\n");
    }
    int node;
    printf("from where to start\n");
    scanf("%d", &node);
    dfs(adjlist, node);
    return 0;
}