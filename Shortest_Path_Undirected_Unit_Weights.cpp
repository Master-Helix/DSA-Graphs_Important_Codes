// SHORTEST PATH for UNDIRECTED GRAPH with all Edges of Weight=1 from a Source

void Shortest_dist_Undirected_unit_weight(vector<int>adj[],int v,int src)
{
	int dist[v+1];
	for(int i=0;i<=v;i++)
	{
		dist[i]=INT_MAX;
	}
	queue<int>q;
	q.push(src);
	dist[src]=0;


	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(auto it:adj[k])
		{
			if(dist[k]+1<dist[it])
			{
				dist[it]=dist[k]+1;
				q.push(it);
			}
		}
	}

	for(int i=0;i<=v;i++)
	{
		cout<<i<<"--->"<<dist[i]<<endl;
	}
}