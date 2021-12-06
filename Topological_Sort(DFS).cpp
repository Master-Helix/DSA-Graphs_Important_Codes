// TOPOLOGICAL SORT using DFS

void find_topo(vector<int>adj[],vector<int>&visited,stack<int>&st,int i)
{
	visited[i]=1;
	for(auto it:adj[i])
	{
		if(!visited[it])
		{
			find_topo(adj,visited,st,it);
		}
	}
	st.push(i);
}

vector<int> TOPO_Sort(vector<int>adj[],int v)
{
	vector<int>visited(v,0);
	stack<int>st;
	for(int i=0;i<=v;i++)
	{
		if(visited[i]==0)
		{
			find_topo(adj,visited,st,i);
		}
	}

	vector<int>ans;
	while(!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}
