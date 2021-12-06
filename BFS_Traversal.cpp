// BFS Traversal
void BFS(vector<int>adj[],int v)
{
	bool visited[v+1]={false};

	queue<int>q;
	for(int i=0;i<=v;i++)
	{
		if(visited[i]==false)
		{
			q.push(i);
			visited[i]=true;
			while(!q.empty())
			{
				int k=q.front();
				q.pop();
				cout<<k<<" ";


				for(auto it:adj[k])
				{
					if(visited[it]==false)
					{
						visited[it]=true;
						q.push(it);
					}
				}
			}
		}
	}
}
