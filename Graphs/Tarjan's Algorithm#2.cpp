/*
 * To find articulation points in a graph.
 * Time complexity :- O(E+V)
 */  
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[101];
vector<int> in,low;
vector<bool> vis;
int timer;
vector<int> art_pts;

void dfs(int node,int par)
{
    vis[node]=true;
    in[node]=low[node]=timer;
    timer++;
    int child=0;
    bool isArtPt=false;
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
            if(in[node]<=low[x]&&par!=-1)
            isArtPt=true;

            child++;
        }
    }
    if(par==-1&&child>1)
    isArtPt=true;

    if(isArtPt)
        art_pts.push_back(node);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif

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

    for(int i=0;i<n;i++)
      if(!vis[i])
        dfs(i,-1);

    cout<<art_pts.size()<<"\n";
    for(auto it:art_pts)
        cout<<it<<"\n";

    return 0;
}
