/*
 * To find bridges in a graph.
 * Time complexity :- O(E+V)
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[101];    // adjacency list
vector<int> in,low;      // in is in time of nodes and low is the in time of lowest ancestor(not parent) which is connected to the node.
vector<bool> vis;
int timer; 
vector<pair<int,int>> bridges;  // pair of nodes forming bridges

void dfs(int node,int par)
{
    vis[node]=true;
    in[node]=low[node]=timer;
    timer++;
    for(int x:adj[node])
    {
        if(x==par)
            continue;
        if(vis[x])
        {
            // back edge
            low[node]=min(low[node],in[x]);
        }
        else
        {
            // forward edge
            dfs(x,node);
            low[node]=min(low[node],low[x]);
            if(in[node]<low[x])
                bridges.push_back({node,x});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin>>n;  // no of nodes
    int e;cin>>e;  // no of edges
    
    while(e--)
    {
        int x,y;      // nodes
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    in.assign(n,-1);
    low.assign(n,-1);
    vis.assign(n,false);
    timer=0;

    dfs(0,-1);

    cout<<bridges.size()<<"\n";
    for(auto it:bridges)
        cout<<it.first<<" "<<it.second<<"\n";

    return 0;
}
