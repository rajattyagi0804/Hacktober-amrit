#include<bits/stdc++.h>
using namespace std;
#define V 5

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

int printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}
  

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 
    bool sptSet[V]; 
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
  
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        
        int u = minDistance(dist, sptSet);
  
      
        sptSet[u] = true;
  
      
        for (int v = 0; v < V; v++)
  
           
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
  
    // print the constructed distance array
    printSolution(dist, V);
}
  
// driver program to test above function
int main()
{

    int graph[V][V] ;
    cout<<"Enter the distance matrix";
    for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
    cin>>graph[i][j];
  
    dijkstra(graph, 0);
  
    return 0;
}