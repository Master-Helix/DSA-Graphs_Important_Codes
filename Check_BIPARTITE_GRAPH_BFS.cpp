// Check if Graph is BIPARTITE GRAPH or not using BFS

bool Check_Bipartite_BFS(vector<int>adj[],int i,int color[])
{
        // for two colours , we will use 0 and 1 alternatively
	
	queue<int>q;
	q.push(i);.
	color[i]=1;
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(auto it:adj[k])
		{
			if(color[it]==-1)
			{
				color[it]=1-color[k];
				q.push(it);
			}
			else if(color[it]==color[k])
			{
				return false;
			}
		}
	}
	return true;

}


bool is_Bipartite_BFS(vector<int>adj[],int v)
{
	int color[v+1]={-1};
	for(int i=0;i<=v;i++)
	{
		if(color[i]==-1)
		{
			if(Check_Bipartite_BFS(adj,i,color)==false)
			{
				return false;
			}
		}
	}
	return true;
}
