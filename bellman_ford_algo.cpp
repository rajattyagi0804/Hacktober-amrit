#include <bits/stdc++.h>
using namespace std;

struct Edge {
   int src, dest, weight;
};

struct Graph {
   int V, E;
   struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
   struct Graph* graph = new Graph;
   graph->V = V;
   graph->E = E;
   graph->edge = new Edge[E];
   return graph;
}

void BellmanFord(struct Graph* graph, int src) {
   int V = graph->V;
   int E = graph->E;
   int dist[V];

   for (int i = 0; i < V; i++) dist[i] = INT_MAX;

   dist[src] = 0;

   for (int i = 1; i <= V - 1; i++) {
      for (int j = 0; j < E; j++) {
         int u = graph->edge[j].src;
         int v = graph->edge[j].dest;
         int weight = graph->edge[j].weight;
         if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
         dist[v] = dist[u] + weight;
      }
   }

   for (int i = 0; i < E; i++) {
      int u = graph->edge[i].src;
      int v = graph->edge[i].dest;
      int weight = graph->edge[i].weight;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
         cout<<"Graph contains negative weight cycle"<<endl;
         return;
      }
   }

   printf("Vertex :\t\t\t ");
   for (int i = 0; i < V; ++i)
      printf("%d \t", i);
      printf("\nDistance From Source : ");
   for (int i = 0; i < V; ++i)
      printf("%d \t",dist[i]);

   return;
}

int main() {
   int V = 5;
   int E = 8;
   struct Graph* graph = createGraph(V, E);

   int s,d,w;

   for(int i=0;i<E;++i){
      cin>>s>>d>>w;
      graph->edge[i].src=s;
      graph->edge[i].dest=d;
      graph->edge[i].weight=w;
   }
   BellmanFord(graph, 0);
   return 0;
}
