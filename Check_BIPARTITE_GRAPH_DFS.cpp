// Check BIPARTITE GRAPH using DFS Traversal

bool Check_Bipartite_DFS(vector<int>adj[],int color[],int i)
{
	if(color[i]==-1)
	{
		color[i]=1;
	}

	for(auto it:adj[i])
	{
		if(color[it]==-1)
		{
			color[it]=1-color[i];
			if(!Check_Bipartite_DFS(adj,color,it))
			{
				return false;
			}
		}
		else if(color[it]==color[i])
		{
			return false;
		}
	}
	return true;
}


bool is_Bipartite_DFS(vector<int>adj[],int v)
{
	int color[v+1]={-1};

	for(int i=0;i<=v;i++)
	{
		if(color[i]==-1)
		{
			if(Check_Bipartite_DFS(adj,color,i)==false)
			{
				return false;
			}
		}
	}
	return true;
}