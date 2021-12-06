void PRIM_algo(vector<pair<int,int>>adj[],int v)
{
	int parent[v+1];
	int key[v+1];
	int mst[v+1];

	for(int i=0;i<=v;i++)
	{
		key[i]=INT_MAX;
		mst[i]=false;
	}

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

	key[0]=0;
	parent[0]=-1;
	pq.push({0,0}); // first is distance and second is vertex no.

	for(int i=0;i<v;i++)
	{
		int u=pq.top().second;
		pq.pop();
		mst[u]=true;

		for(auto it:adj[u])
		{
			int k1=it.first;
			int k2=it.second;
			if(mst[k1]==false && k2<key[k1])
			{
				key[k1]=k2;
				parent[k1]=u;
				pq.push({key[k1],k1});
			}
		}
	}

	cout<<"MST- PRIMS ALgo"<<endl;
	for(int i=0;i<=v;i++)
	{
		cout<<parent[i]<<"---"<<i<<endl;
	}
}
