#include<bits/stdc++.h>
using namespace std;


int find(vector<pair<int,int>>&trees, int i)
{
    if (trees[i].second != i)
        trees[i].second = find(trees, trees[i].second);
    return trees[i].second;
}

void Union(vector<pair<int,int>>&trees, int a, int b)
{
    int rootA = find(trees, a);
    int rootB = find(trees, b);

    if (trees[rootA].first < trees[rootB].first)
        trees[rootA].second = rootB;
    else if (trees[rootA].first > trees[rootB].first)
        trees[rootB].second = rootA;

    else
    {
        trees[rootB].second = rootA;
        trees[rootA].first++;
    }
}

void Boruvkas_function(vector<vector<int>>Graph,int V,int E)
{
    vector<pair<int,int>>trees;

    for (int i = 0; i < V; i++)
    {
        trees.push_back(make_pair(0,i));
    }

    int TotalTrees = V;
    int MST_total_weight = 0;


    cout<<"Edges of MST are :-"<<endl;

    while (TotalTrees > 1)
    {
        vector<int> smallest_edge(V,-1);

        for (int i=0; i<E; i++)
        {
            int setA = find(trees, Graph[i][0]);
            int setB = find(trees, Graph[i][1]);

            if (setA == setB)
                continue;

            else
            {
            if (smallest_edge[setA] == -1 ||
                Graph[smallest_edge[setA]][2] > Graph[i][2])
                smallest_edge[setA] = i;

            if (smallest_edge[setB] == -1 ||
                Graph[smallest_edge[setB]][2] > Graph[i][2])
                smallest_edge[setB] = i;
            }
        }

        for (int i=0; i<V; i++)
        {
            if (smallest_edge[i] != -1)
            {
                int setA=find(trees, Graph[smallest_edge[i]][0]);
                int setB=find(trees, Graph[smallest_edge[i]][1]);

                if (setA == setB)
                    continue;
                MST_total_weight += Graph[smallest_edge[i]][2];

                cout<<"Edge ("<<Graph[smallest_edge[i]][0]<<","
                    <<Graph[smallest_edge[i]][1]<<") "<<"weight "
                    <<Graph[smallest_edge[i]][2]<<endl;

                Union(trees, setA, setB);
                TotalTrees--;
            }
        }
    }
    cout<<"Total weight of MST is:"<<MST_total_weight<<endl;
}

int main()
{


    int V;
    int E;
    cin>>V>>E;
    vector<vector<int>>Graph;

    int src,dest,weight;
    for(int i=0;i<E;++i){
        cin>>src>>dest>>weight;
        Graph.push_back({src,dest,weight});
    }

    Boruvkas_function(Graph,V,E);

    return 0;
}
