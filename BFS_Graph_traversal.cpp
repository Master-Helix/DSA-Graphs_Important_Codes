  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        
        vector<int>v;
        bool visited[V+1]={false};
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            v.push_back(k);
            for(int x:adj[k])
            {
                if(visited[x]==false)
                {
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        return v;
    }