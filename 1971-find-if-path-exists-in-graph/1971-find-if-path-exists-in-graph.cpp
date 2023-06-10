class Solution {
public:
    bool pathExists(vector<int>adj[] , vector<int>&vis, int start, int end){
        vis[start] = 1;
         if(end == start)
            return true;
         
        for(auto it: adj[start]){
            if(vis[it] == 0)
                if(pathExists(adj, vis, it, end))
                    return true;
         
        }
            
  return false;
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(vis[i] == 0)
            if(pathExists(adj, vis, source, destination) == true)
                return true;
        }
        return false;
    }
};