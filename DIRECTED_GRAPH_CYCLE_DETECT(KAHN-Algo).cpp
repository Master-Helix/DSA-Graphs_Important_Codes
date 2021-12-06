// Check is there cycle in Directed graph using KAHN ALgo (more easy tahn normal BFS Traversal)

bool Cycle_check_Kahn(vector<int>adj[],int v)
{
	queue<int>q;
	int ctr=0;
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
		ctr++;
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

	if(ctr==v)      // if ctr==number of nodes , that means all nodes have been traversed in topo sort, so no cycle will be there
	{                    // as for topos ort to happen correctly, their should be no cycle 
		return false;
	}

	return true;
}
