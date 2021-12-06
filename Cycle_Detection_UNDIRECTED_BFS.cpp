// CYCLE DETECTION FOR Undirected Graph using BFS

bool check_BFS_cycle(int i,vector<int>adj[],vector<bool>&visited,int v)
{
	queue<pair<int,int>>q;
	q.push({i,-1});

	while(!q.empty())
	{
		int n=q.front().first;
		int par=q.front().second;
		q.pop();
		for(auto it:adj[n])
		{
			if(visited[it]==false)
			{
				visited[it]=true;
				q.push({it,n});
			}
			else if(par!=it)
			{
				return true;
			}
		}
	}
	return false;
}
  
bool is_Cycle_for_BFS(vector<int>adj[],int v)
{
	vector<bool>visited(v+1,false);
	for(int i=0;i<=v;i++)
	{
		if(visited[i]==false)
		{
			if(check_BFS_cycle(i,adj,visited,v)==true)
			{
				return true;
			}
		}
	}
	return false;
}
