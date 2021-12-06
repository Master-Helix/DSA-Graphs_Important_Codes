
// TOPOLOGICAL SORT Using BFS Traversal  - KAHN Algorithm

vector<int>BFS_TopoSort(vector<int>adj[],int v)
{
	queue<int>q;
	vector<int>ans;
	int indegree[v]={0};
	for(int i=0;i<v;i++)
	{
		for(auto it:adj[i])
		{
			indegree[it]++;
		}
	}


	for(int i=0;i<v;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int k=q.front();
		ans.push_back(k);
		q.pop();
		for(auto it:adj[k])
		{
			indegree[it]--;
			if(indegree[it]==0)
			{
				q.push(it);
			}
		}
	}

	return ans;
}