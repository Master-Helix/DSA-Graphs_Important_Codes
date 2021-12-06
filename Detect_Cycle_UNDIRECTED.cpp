bool DFS(vector<int> adj[],int i,bool visited[],int parent)
    {
        visited[i]=true;
        for(int x:adj[i])
        {
            if(visited[x]==false)
            {
                if(DFS(adj,x,visited,i)==true)
                {
                    return true;
                }
            }
                else if(x!=parent)
                {
                    return true;
                }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        
          bool visited[V]={false};
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(DFS(adj,i,visited,-1)==true)
                {
                    return true;
                }
            }
        }
        return false;
        // Code here
    }