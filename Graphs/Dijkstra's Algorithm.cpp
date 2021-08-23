
/* 
 *   It is used to find shortest distance from given node to all other nodes.
 *   It does not works on graph with negative weighted edges.
 *   Time complexity :- O(V + E*logV)
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int,ll>> adj[101];    // adjacency list with weights of edges
vector<ll> dis;                   // to store min distances

void dijkstra(int node)
{
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({node,0});
    dis[node]=0;
    while(!pq.empty())
    {
        int cur=pq.top().first;
        ll d=pq.top().second;
        pq.pop();
        for(auto child:adj[cur])
        {
            if(dis[child.first]>d+child.second)
            {
                dis[child.first]=d+child.second;
                pq.push({child.first,d+child.second});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif

    int n;cin>>n; // no of nodes
    int e;cin>>e; // no of edges
    
    while(e--)
    {
        int x,y; // nodes
        ll d;    // weight
        cin>>x>>y>>d;
        adj[x].push_back({y,d});
        adj[y].push_back({x,d});
    }

    dis=vector<ll> (n,INT_MAX);
    dijkstra(0);

    for(int i=0;i<n;i++)
        cout<<dis[i]<<"\n";
    return 0;
}
