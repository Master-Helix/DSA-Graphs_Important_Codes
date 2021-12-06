#include <bits/stdc++.h>
using namespace std;

#define fast() ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long 
#define l long long


// CODE to find Number of BRIDGES in a Graph using CUT EDGE

void dfs(int node, int parent,vector<int>&visited, vector<int>&tim,vector<int>&low,int &timer,vector<int>adj[])
{
  visited[node]=1;
  tim[node]=low[node]=timer++;
  
  for(auto it:adj[node])
  {
    if(it==parent)
    {
      continue;
    }
    
    if(!visited[it])
    {
      dfs(it,node,visited,tim,low,timer,adj);
      low[node]=min(low[node],low[it]);
      
      if(low[it]>tim[node])
      {
        cout<<node<<"--"<<it<<endl;    // this is a bridge
      }
    }
    else
    {
      low[node]=min(low[node],tim[it]);
    }
  }
}



// RAKSHIT PANDEY
int main()
{
  fast();
  
  int n,m;
  cin>>n>>m;
  vector<int>adj[n];
  
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector<int>tim(n,-1);
  vector<int>low(n,-1);
  vector<int>visited(n,0);
  
  int timer=0;
  for(int i=0;i<n;i++)       // loop used if there are multiple components
  {
    if(!visited[i])
    {
      dfs(i,-1,visited,tim,low,timer,adj);
    }
  }
  
  
}