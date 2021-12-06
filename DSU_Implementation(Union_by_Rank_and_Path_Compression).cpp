#include <bits/stdc++.h>
using namespace std;

#define fast() ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long 
#define l long long


// IMPLEMENTATION OF DISJOINT SET UNION WITH union by rank and Path Compression
int parent[1000];
int rank[1000];



void makeSet(int n)
{
  for(int i=0;i<=n;i++)
  {
    rank[i]=0;
    parent[i]=i; // at first every node is parent of itself
  }
}

int findParent(int node)
{
  if(node==parent[node])
  {
    return node;
  }
  
  return parent[node]=findParent(parent[node]);   // this will do path compression as parent[node] will only store the final parent an return that
}


void Union(int u,int v)
{
  u=findParent(u);
  v=findParent(v);
  
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
  
  int n;
  cin>>n;
  makeSet(n);
  
  int m;
  cin>>m;
  while(m--)
  {
    int u,v;
    cin>>u>>v;
    Union(u,v);
  }
  
  // To check the parent of the node
  
  int node;
  cin>>node;
  int p=findParent(node);
  cout<<p<<endl;
  
}