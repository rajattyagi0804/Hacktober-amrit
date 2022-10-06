#include <bits/stdc++.h>
using namespace std;

struct pair_cmp {
    constexpr bool operator()(
        pair<int,pair<int,string>> const& a,
        pair<int,pair<int,string>> const& b)
    {
        return a.first > b.first; //do you want to push b front? If b is smaller, YES else NO
    }
};

vector<pair<int,string>> single_source_shortest_path(
    vector<vector<pair<int,int>>>& adj,
    int source,
    int n //number of nodes
){
    priority_queue<pair<int,pair<int,string>>,vector<pair<int,pair<int,string>>>,pair_cmp> pq; //node,distance,path
    pq.push(make_pair(0,make_pair(source,"0")));//distance,node,path
    set<int> seen;
    vector<pair<int,string>> ans(n,make_pair(INT_MAX,"")); //distance,path from source to destination

    while(!pq.empty()){
        pair<int,pair<int,string>> item = pq.top();

        //if already seen, then dont explore
        while(!pq.empty() && seen.find(item.second.first) != seen.end()){
            pq.pop();
            item = pq.top();
        }

        if(pq.empty()){
            break;
        }

        //visited node
        // cout << "item: "<<item.second.first << ","<<item.first<<","<<item.second.second<< endl;
        seen.insert(item.second.first);
        ans[item.second.first] = make_pair(item.first,item.second.second); //update distance and path

        const vector<pair<int,int>>& neighbours = adj[item.second.first];
        for(auto nei : neighbours){
            // cout << "nei: "<<nei.first<<","<<nei.second<<endl;

            //if not visited yet ie not found in set
            if(seen.find(nei.first)==seen.end()){
                int new_d = nei.second + item.first;
                string path = item.second.second + "," + to_string(nei.first);
                // cout << "new dist and path "<<new_d <<" "<<path<<endl;
                
                pq.push(make_pair(new_d,make_pair(nei.first,path)));
            }
        }
    }

    return ans;
}

int main(){
    cout << "Enter number of nodes\n";
    int n;
    cin >> n;

    cout << "Enter number of edges\n";
    int e;
    cin >> e;

    vector<vector<pair<int,int>>> adj;
    for(int i = 0;i<n;i++){
        vector<pair<int,int>> row;
        adj.push_back(row);
    }

    cout << "Enter source,destination,weight\n";
    int src,dst,wt;
    for(int i = 0;i<e;i++){
        cin >> src;
        cin >> dst;
        cin >> wt;

        adj[src].push_back(make_pair(dst,wt));
    }

    int source;
    cout << "Enter source\n";
    cin >> source;

    vector<pair<int,string>> ans = single_source_shortest_path(adj,source,n);
    int destination = 0;
    for(auto item : ans){
        cout << "Distance to "<<destination<<" is "<<item.first;
        cout<<" and the Shortest path is "<<item.second<<endl;
        destination+=1;
    }

    return 0;
}