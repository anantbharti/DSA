/*
 * To find minimum spanning tree of a graph.
 * Time complexity :- O(V*V*logE)
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int,int>> adj[101];     // adjacency list 
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
vector<bool> vis;
vector<vector<int>> mst;     // edges with weight in minimum spanning tree
int n,no_of_nodes;      // no_of_nodes is current no of nodes included in mst during dfs.
int ans;        // total weight of minimum spanning tree

void dfs(int node,int par)
{
    if(no_of_nodes==n)return;  
    no_of_nodes++;
    vis[node]=true;
    
    for(auto it:adj[node])
    {
        if(!vis[it.first])
        pq.push({it.second,{node,it.first}});
    }
    while(!pq.empty())
    {
        int u=pq.top().second.first;
        int v=pq.top().second.second;
        int d=pq.top().first;
        pq.pop();
        if(vis[v])
        continue;
        else
        {
            mst.push_back({u,v,d});
            ans+=d;
            dfs(v,node);
            break;
        }
    }
}

typedef pair<int,int> pii;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    n;cin>>n;  // no of nodes
    int e;cin>>e;  // no of edges
    while(e--)
    {
        int x,y;   // nodes
        cin>>x>>y;
        int d;cin>>d;
        adj[x].push_back({y,d});
        adj[y].push_back({x,d});
    }
    vis.assign(n,false);
    ans=0;
    no_of_nodes=0;
    dfs(0,-1);

    cout<<ans<<"\n";
    for(auto it:mst)
    {
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"\n";
    }

    return 0;
}
