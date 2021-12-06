 // Function to return a list containing the DFS traversal of the graph.
     bool visited[10000]={false};
     
    void DFS_r(vector<int> adj[],vector<int>&v,int flag)
    {
        if(visited[flag]==false)
        {
            visited[flag]=true;
            v.push_back(flag);
        }
        for(int x:adj[flag])
        {
            if(visited[x]==false)
            {
                DFS_r(adj,v,x);
            }
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        
        vector<int>v;
            DFS_r(adj,v,0);
        
        return v;
    }