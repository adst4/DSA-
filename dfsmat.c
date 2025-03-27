#include<stdio.h>
#include<stdlib.h>
 void dfs(int a[10][10], int node, int n,int visited[]){
 printf("%d\t",node);
 visited[node]=1;
 for(int i=1;i<=n;i++){
 if(a[node][i]==1 && visited[i]==0){
 visited[i]=1;
 dfs(a,i,n,visited);
 }
 }
 }
 void main(){
 int a[10][10];
 int visited[10]={0};
 int i,n,j;
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
 printf("from where to start\n");
 scanf("%d",&i);
 dfs(a,i,n,visited);
}