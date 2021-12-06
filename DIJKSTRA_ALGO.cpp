// DIJKSTRA ALGO for Shortest Path between two vertex for UNDIRECTED Graph with different Weights
void DIJKSTRA(vector<pair<int,int>>adj[],int v,int src)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // min-heap
	vector<int>dist(v+1,INT_MAX);
	dist[src]=0;
	pq.push({0,src});
	while(!pq.empty())
	{
		auto k=pq.top();
		int distance=k.first;
		int node=k.second;
		pq.pop();
		for(auto it:adj[node])
		{
			int n1=it.first;
			int n2=it.second;
			if(dist[n1]>dist[node]+n2)
			{
				dist[n1]=dist[node]+n2;
				pq.push({dist[n1],n1});
			}
		}
	}

	cout<<endl<<"DIJKSTRA Algo"<<endl;
	cout<<"The distances from source are :"<<endl;
	for(int i=0;i<=v;i++)
	{
		cout<<src<<"--->"<<i<<"=="<<dist[i]<<endl;
	}

}