// DFS Traversal
void DFS(vector<bool> &visited,vector<int>adj[],int i) // this is Recursive Function
{
	cout<<i<<" ";
	visited[i]=true;
	for(auto it:adj[i])
	{
		if(!visited[it])
		{
			DFS(visited,adj,it);
		}
	}

}

void DFS_Util(vector<int>adj[],int v)
{
	vector<bool>visited(v,false);
	for(int i=0;i<=v;i++)
	{
		if(visited[i]==false)
		{
			DFS(visited,adj,i);
		}
	}
}