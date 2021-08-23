/*
 * It is used to find the number of strongly connected components in a directed graph
 * Time complexity:-  O(2*(E+V))
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[101],rev[101];
vector<bool> vis;
int n;
stack<int> stk;

void dfs1(int node)
{
    vis[node]=true;
    for(int x:adj[node])
    {
        rev[x].push_back(node);
        if(!vis[x])
            dfs1(x);
    }
    stk.push(node);
}

void dfs2(int node,vector<int>&v)
{
    vis[node]=true;
    v.push_back(node);
    for(int x:rev[node])
    {
        if(!vis[x])
            dfs2(x,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  
    cin>>n;       // no of nodes
    int e;cin>>e; // no of edges
    
    while(e--)
    {
        int x,y; // nodes
        cin>>x>>y;
        adj[x].push_back(y);
    }

    vis=vector<bool>(n,false);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs1(i);
    }
    int nocc=0;    // no of strongly connected components
    vector<vector<int>> ans;   //nodes in strongly connected components
    vis=vector<bool>(n,false);
    while(!stk.empty())
    {
        if(!vis[stk.top()])
        {
            nocc++;
            vector<int> v;
            dfs2(stk.top(),v);
            ans.push_back(v);
        }
        stk.pop();
    }
    cout<<nocc<<"\n";
    for(auto it:ans)
    {
        for(auto x:it)
            cout<<x<<" ";
        cout<<"\n";
    }
    
    return 0;
}


