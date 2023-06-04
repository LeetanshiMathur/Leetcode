class Solution {
public:
        void dfs(vector<vector<int>> &isConnected, vector<int> &vis, int u, int nodes) {
        // cout<<u<<" ";
        vis[u]=1;
        for(int v=0; v<nodes; v++) {
            if(u!=v && isConnected[u][v]==1) {
                if(!vis[v]) {
                    dfs(isConnected, vis, v, nodes);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int nodes = isConnected.size();
        vector<int> vis(nodes, 0);
        int cnt=0;
        for(int i=0; i<nodes; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(isConnected, vis, i, nodes);
            }
            
        }
        
        return cnt;
    }
};