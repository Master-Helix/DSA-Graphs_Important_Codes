#include <bits/stdc++.h>
using namespace std;

#define fast() ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long 
#define l long long


// CODE for KOSARAJU Algo to find Strongly Connected Components

void dfs(int node,stack<int>&st,vector<int>&visited,vector<int>adj[]){
  
  visited[node]=1;
  for(auto it:adj[node])
  {
    if(!visited[it])
    {
      dfs(it,st,visited,adj);
    }
  }
  
  st.push(node);
}

void reverse_dfs(int node, vector<int>&visited,vector<int>transpose[])
{
  cout<<node<<" ";
  visited[node]=1;
  for(auto it:transpose[node])
  {
    if(!visited[it])
    {
      reverse_dfs(it,visited,transpose);
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
    adj[u].push_back(v);   // created a Directed Graph
  }
  
  stack<int>st;
  vector<int>visited(n,0);
  
  for(int i=0;i<n;i++)        // topo sort
  {
    if(visited[i]==0)
    {
      dfs(i,st,visited,adj);
    }
  }
  
  vector<int>transpose[n];
  
  for(int i=0;i<n;i++)
  {
    visited[i]=0;
    for(auto it:adj[i])          // transpose the graph it->i edge
    {
      transpose[it].push_back(i);
    }
  }
  
  
  while(!st.empty())
  {
    int node=st.top();
    st.pop();
    if(!visited[node])
    {
      cout<<"SCC: ";
      reverse_dfs(node,visited,transpose);
      cout<<endl;
    }
  }
  
}