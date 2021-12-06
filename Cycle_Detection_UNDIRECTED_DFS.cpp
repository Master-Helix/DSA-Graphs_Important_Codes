// Check Cycle in UnDirected graph using DFS Traversal

bool check_DFS_Cycle(vector<bool>&visited,vector<int>adj[],int i,int parent)
{
	visited[i]=true;
	for(auto it:adj[i])
	{
		if(!visited[i])
		{
			if(check_DFS_Cycle(visited,adj,it,i))
			{
				return true;
			}
		}
		else
		{
			if(parent!=i)
			{
				return true;
			}
		}
	}
	return false;
}

bool is_DFS_Cycle(vector<int>adj[],int v)
{
	vector<bool>visited(v+1,false);
	for(int i=0;i<=v;i++)
	{
		if(!visited[i])
		{
			if(check_DFS_Cycle(visited,adj,i,-1)==true)
			{
				return true;
			}
		}
	}
	return false;
}
