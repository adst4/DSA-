#include<stdio.h>
#include<stdlib.h>

 void bfs(int a[10][10],int n){
 int visited[10]={0};
 int queue[10],front=-1,rear=-1,node;
 printf("where to start\n");
 scanf("%d",&node);
 printf("%d\t",node);
 visited[node]=1;
 queue[++rear]=node;
 while(front<rear){
 node=queue[++front];
 for(int i=1;i<=n;i++){
 if(a[node][i]==1 && visited[i]==0){
 visited[i]=1;
 queue[++rear]=i;
 printf("%d\t",i);
 }
 }
 }

 }
 void main()
 {
 int a[10][10], i,j,n;
 printf("how many vertices\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++){
 for(j=1;j<=n;j++){
 a[i][j]=0;
 if(i!=j){
 printf("Is there any edge between vertex %d and %d (1/0)",i,j);
 scanf("%d", &a[i][j]);
 }
}
}
bfs(a,n);
}