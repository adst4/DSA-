#include <stdio.h>

 struct Edge {
 int source, destination, weight;
 };

 struct Edge edges[101];
 int parent[101];

 int find(int node) {
 while (parent[node] != node)
 node = parent[node];
 return node;
 }
 
  void unionSets(int u, int v) {
 parent[find(u)] = find(v);
 }

 void bubbleSort(int count) {
 for (int i = 1; i < count; i++) {
 for (int j = 1; j < count - i + 1; j++) {
 if (edges[j].weight > edges[j + 1].weight) {
 struct Edge temp = edges[j];
 edges[j] = edges[j + 1];
 edges[j + 1] = temp;
 }
 }
 }
 }

 void kruskal(int nodes, int edgesCount) {
 int mstWeight = 0, edgeCount = 0;

 bubbleSort(edgesCount);

 for (int i = 1; i <= nodes; i++)
 parent[i] = i;

 printf("\nSelected edges for the Minimum Spanning Tree:\n");

 for (int i = 1; i <= edgesCount; i++) {
 if (edgeCount == nodes - 1)
 break;
  if (find(edges[i].source) != find(edges[i].destination)) {
 printf("Edge: %d--->%d | Weight: %d\n", edges[i].source, edges[i].destination,
edges[i].weight);
 mstWeight += edges[i].weight;
 unionSets(edges[i].source, edges[i].destination);
 edgeCount++;
 }
 }

 printf("Total weight of the Minimum Spanning Tree: %d\n", mstWeight);
 }

 int main() {
 int nodes, edgesCount;

 printf("Enter the number of nodes in the graph: ");
 scanf("%d", &nodes);

 printf("Enter the number of edges in the graph: ");
 scanf("%d", &edgesCount);

 printf("\nEnter the details of each edge:\n");
 for (int i = 1; i <= edgesCount; i++) {
 printf("\nEdge %d:\n", i);
 printf(" Enter the source node: ");
 scanf("%d", &edges[i].source);
 printf(" Enter the destination node: ");
 scanf("%d", &edges[i].destination);
 printf(" Enter the weight of the edge: ");
 scanf("%d", &edges[i].weight);
 }

 kruskal(nodes, edgesCount);
 return 0;
 }