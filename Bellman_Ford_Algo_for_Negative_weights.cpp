#include <bits/stdc++.h>
using namespace std;

#define fast() ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long 
#define l long long


// CODE for BELLMAN-FORD to Find shortest path with negative weights and also if there is negative cycle or not

struct Node{
  int u,v,wt;
  Node(int a,int b,int c)
  {
    u=a;v=b;wt=c;
  }
};


// RAKSHIT PANDEY
int main()
{
  fast();
  
  int n,m;
  cin>>n>>m;
  
  vector<Node>edges;
  
  for(int i=0;i<m;i++)
  {
    int u,v,wt;
    cin>>u>>v>>wt;
    edges.push_back(Node(u,v,wt));
  }
  
  int src;
  cin>>src;  // source point
  
   int inf = 10000000; 
  vector<int>dist(n,inf);
  
  dist[src]=0;
  
  for(int i=1;i<=n-1;i++)          // this is Relax method which runs for n- times
  {
    for(auto it:edges)
    {
      if(dist[it.u]+it.wt<dist[it.v])  // this condition is important
      {
        dist[it.v]=it.wt+dist[it.u];
      }
    }
  }
  
 
 int flag=0;
 for(auto it:edges)     // this relax method is run again for nth time to check if there is negative cycle in the graph or not
 {
   if(dist[it.u]+it.wt<dist[it.v])
   {
     cout<<"Negative cycle exists !"<<endl;
     flag=1;
     break;
   }
 }
 
 
 if(!flag)                      
 {
   for(int i=0;i<n;i++)             // pritning the shortest distance for each vertex
   {
     cout<<i<<"-->"<<dist[i]<<endl;
   }
 }
  
}