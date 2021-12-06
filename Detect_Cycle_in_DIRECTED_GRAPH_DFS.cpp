// Detect Cycle in DIRECTED GRAPH using DFS Traversal

bool Check_Cycle_Directed_DFS(vector<int>adj[],int visited[],int dfs_visit[],int i)
{
	visited[i]=1;
	dfs_visit[i]=1;
	for(auto it:adj[i])
	{
		if(visited[i]==0)
		{
			if(Check_Cycle_Directed_DFS(adj,visited,dfs_visit,it))
			{
				return true;
			}
		}
		else if(dfs_visit[it]==1)
		{
			return true;
		}
	}
	dfs_visit[i]=0;
	return false;
}

bool Is_Cyclic_Directed_DFS(vector<int>adj[],int v)
{
	int visited[v]={0};
	int dfs_visit[v]={0}; // this array is used to check which nodes are visited in one recursion call , else mark them unvisited

	for(int i=0;i<v;i++)
	{
		if(visited[i]==0)
		{
			if(Check_Cycle_Directed_DFS(adj,visited,dfs_visit,i))
			{
				return true;
			}
		}
	}
	return false;
}
