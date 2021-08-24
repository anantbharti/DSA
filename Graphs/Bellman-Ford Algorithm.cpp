/*
 * Used to find shortest distance between given node and all other nodes.
 * Used even if negative weighted edges are present.
 * Used to detect negative weight edge cycle :- we find the shortest distance from source node to all nodes by relaxing distances exactly V-1 times.
 * If any of the shortest distances changes in Vth iteration the it has a negative weight cycle.
 * Time complexity :- O(V*E)
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int,ll>> adj[101];   // adjacency list
vector<ll> dis;                  // shortest distance
int n;                           // number of nodes

void relax(int node)
{
    if(dis[node]==INT_MAX)return;
    for(auto it:adj[node])
    dis[it.first]=min(dis[it.first],dis[node]+it.second);
}
void bellmanFord(int node)
{
    dis[node]=0;
    for(int i=1;i<n;i++)
    for(int j=0;j<n;j++)
        relax(j);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin>>n;       // no of nodes
    int e;cin>>e; // no of edges
    
    while(e--)
    {
        int x,y; // nodes
        ll d;    // distance
        cin>>x>>y>>d;
        adj[x].push_back({y,d});
        adj[y].push_back({x,d});
    }

    dis=vector<ll> (n,INT_MAX);
    bellmanFord(0);

    for(int i=0;i<n;i++)
        cout<<dis[i]<<"\n";
    return 0; 
}
