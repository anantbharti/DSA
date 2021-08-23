/*
 * To sort directed acyclic graph such that for each edge from v1 to v2 then, v1 comes before v2 in sorted array of nodes.
 * Time complexity :- O(E+V)
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[101];
vector<bool> vis;
vector<int> ans;    // to store topologically sorted nodes

void topologicalSort(int node)
{
    vis[node]=true;
    for(auto x:adj[node])
    {
        if(!vis[x])
            topologicalSort(x);
    }
    ans.push_back(node);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin>>n;       // no of nodes
    int e;cin>>e;       // no of edges
    
    while(e--)
    {
        int x,y; // nodes
        cin>>x>>y;
        adj[x].push_back(y);
    }

    vis.assign(n,false);

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            topologicalSort(i);
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)
        cout<<x<<" ";
    
    return 0;
}
