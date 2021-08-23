/*
 * To find shortest distance between all pairs of nodes 
 * Sort of dp
 * Time complexity :- O(V*V*V)
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin>>n;  // no of nodes
    int e;cin>>e;  // no of edges
    vector<vector<ll>> adj(n,vector<ll>(n,INT_MAX));   // adjacency matrix with distance
    while(e--)
    {
        int x,y;      // nodes
        cin>>x>>y;
        ll d;cin>>d;  // weight
        adj[x][y]=d;
    }

    for(int i=0;i<n;i++)
        adj[i][i]=0;   // distance from same node to same node is 0

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    for(int k=0;k<n;k++)
    {
        if(adj[j][i] != INT_MAX && adj[i][k] != INT_MAX)
        adj[j][k] = min( adj[j][k], adj[j][i] + adj[i][k] );
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        if(adj[i][j]!=INT_MAX)
            cout<<adj[i][j]<<" ";
        else
            cout<<"INF ";
        cout<<"\n";
    }
    
    return 0;
}

