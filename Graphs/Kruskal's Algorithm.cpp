vector<int> rank,parent;  //for DSU
vector<vector<int>> edges;

void buildDSU()
{
    for(int i=0;i<rank.size();i++)
    {
        rank[i]=0;
        parent[i]=i;
    }
}

int getParent(int node)
{
    if(node==parent[node])
    return node;

    // path compression
    return parent[node]=getParent(parent[node]);
}

void unite(int node1,int node2)
{
    int par1=getParent(node1);
    int par2=getParent(node2);

    if(rank[par1]>rank[par2])
    {
        parent[par2]=par1;
    }
    else if(rank[par1]<rank[par2])
    {
        parent[par1]=par2;
    }
    else
    {
        parent[par1]=par2;
        rank[par2]++;
    }
}

bool inSameSet(int node1,int node2)
{
  return getParent(node1)==getParent(node2);
}


int spanningTree(int V, vector<vector<int>> adj[])
{
    rank.assign(V,0);
    parent.assign(V,0);
    buildDSU();

    edges.clear();

    for(int i=0;i<V;i++)
    for(auto it:adj[i])
    edges.push_back({it[1],i,it[0]});

    sort(edges.begin(),edges.end());

    int ans=0;
    for(int i=0;i<edges.size();i++)
    {
        if(!inSameSet(edges[i][1],edges[i][2]))
        {
            ans+=edges[i][0];
            unite(edges[i][1],edges[i][2]);
        }
    }

    return ans;
}
