 bool DFSRec(vector<int> adj[], int s,bool visited[], bool recSt[]) 
{ 	
    visited[s]=true;
    recSt[s]=true;
    
    for(int u:adj[s]){
        if(visited[u]==false && DFSRec(adj,u,visited,recSt)==true)
                {return true;}
        else if(recSt[u]==true)
            {return true;}
    }
    recSt[s]=false;
    return false;
}
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        bool visited[V]; 
	for(int i=0;i<V; i++) 
		visited[i] = false;
	bool recSt[V]; 
	for(int i=0;i<V; i++) 
		recSt[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            if(DFSRec(adj,i,visited,recSt)==true)
                return true;
    }
    return false;
    }