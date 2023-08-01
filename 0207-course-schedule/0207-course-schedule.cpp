// class Solution {
// public:


// vector<int>* createAdjacencyList(int num ,vector<vector<int>>& prerequisites) {
//     vector<int>* adjacencyList = new vector<int>[num]; 
//     for (const auto& pair : prerequisites) {
//         int a = pair[1];
//         int b = pair[0];
//         adjacencyList[a].push_back(b);
//     }
//     return adjacencyList;
// }
//  bool dfsCheck(int node, vector<int>adj[], int vis[], int pathVis[]){
//      vis[node]=1;
//      vis[node] = 1;
     //traverse for adjacent nodes
     // for(auto it : adj[node]){
     //     if(!vis[it]){
     //         if(dfsCheck(it, adj, vis, pathVis) == true)
     //             return true;
     //     }
         //if the node has been previously visited but it has to be visited on the same 
//          else if(pathVis[it]){
//              return true;
//          }
//      }
//      pathVis[node]=0;
//      return false;
//  }
    
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int>* adj = new vector<int>[numCourses]; 
//      adj = createAdjacencyList(numCourses, prerequisites);
//       int vis[numCourses]  ;
//       int pathVis[numCourses] ;
//       for(int i=0; i<numCourses; i++){
//           if(!vis[i]){
//               if(dfsCheck(i, adj, vis, pathVis) == true)
//                   return true;
//           }
//       }
//         return false;
//     }
// };
class Solution {
public:
    vector<int>* createAdjacencyList(int num, vector<vector<int>>& prerequisites) {
        vector<int>* adjacencyList = new vector<int>[num];
        for (const auto& pair : prerequisites) {
            int a = pair[1];
            int b = pair[0];
            adjacencyList[a].push_back(b);
        }
        return adjacencyList;
    }

    bool dfsCheck(int node, vector<int>* adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        // traverse for adjacent nodes
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis))
                    return true;
            } else if (pathVis[it]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>* adj = createAdjacencyList(numCourses, prerequisites);
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis))
                    return false; // If there is a cycle, return false
            }
        }
        delete[] adj; // Don't forget to release the allocated memory
        return true; // If there is no cycle, return true
    }
};
