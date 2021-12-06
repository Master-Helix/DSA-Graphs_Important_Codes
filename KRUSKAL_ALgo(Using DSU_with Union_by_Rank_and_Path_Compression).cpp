#include <bits/stdc++.h>
using namespace std;

#define fast() ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long 
#define l long long


// IMPLEMENTATION OF KRUSKAL ALGO using DSU 

struct Node{
  int u;
  int v;
  int wt;
  
  Node(int k1,int k2,int k3)
  {
    u=k1;
    v=k2;
    wt=k3;                         // u and v are edges point and wt is weight of edge
  }
};

bool cmp(Node a,Node b)
{
  return a.wt<b.wt;   // sort the Node according to weight
}



int findParent(int node,vector<int>&parent)
{
  if(node==parent[node])
  {
    return node;
  }
  
  return findParent(parent[node],parent);   // this will do path compression as parent[node] will only store the final parent an return that
}


void Union(int u,int v,vector<int> &parent,vector<int> &rank)
{
  u=findParent(u,parent);
  v=findParent(v,parent);
  
  if(rank[u]<rank[v])
  {
    parent[u]=v;
  }
  else if(rank[u]>rank[v])
  {
    parent[v]=u;
  }
  else
  {
    parent[v]=u;
    rank[u]++;
  }
}



// RAKSHIT PANDEY
int main()
{
  fast();
  
  vector<Node>edges; // to store all the Nodes
  
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int u,v,wt;
    cin>>u>>v>>wt;
    edges.push_back(Node(u,v,wt));
  }
  
  sort(edges.begin(),edges.end(),cmp);
  
  vector<int>parent(n);
  for(int i=0;i<n;i++)
  {
    parent[i]=i;
  }
  vector<int>rank(n,0);
  
  int cost=0;  // cost of making the Minimum Spanning Tree
  vector<pair<int,int>>mst;  // to store edges that form Minimum Spanning Tree
  for(auto it:edges)
  {
    if(findParent(it.v,parent)!=findParent(it.u,parent))
    {
      cost+=it.wt;
      mst.push_back({it.u,it.v});
      Union(it.u,it.v,parent,rank);
    }
  }
  
  // Printing edges
  
  for(int i=0;i<mst.size();i++)
  {
    auto p=mst[i];
    cout<<p.first<<"-->"<<p.second<<endl;
  }
  
}