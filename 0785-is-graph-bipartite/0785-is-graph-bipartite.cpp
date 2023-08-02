class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
       queue<int>q;
        // q.push(0);
        int color[V];
        for(int i=0; i<V; i++)color[i]=-1;
//         color[0] = 0;
        
        for (int startNode = 0; startNode < V; startNode++) {
        if (color[startNode] == -1) {
            q.push(startNode);
            color[startNode] = 0;
             while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        }
        }
        return true;
    }
};