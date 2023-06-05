class Solution {
public:
//     void bfs(int row , int col, vector<vector<int>>vis , vector<vector<char>>grid){
//         vis[row][col] = 1;
//         queue<pair<int,int>>q;
//         q.push({row,col});
//         while(!q.empty()){
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();
//             int delrow[] = {-1, 0, 1, 0};
//             int delcol[] = {0, 1, 0, -1};
//             for(int i=0; i<4; i++){
//                 int nrow = row+delrow[i];
//                 int ncol = col+delcol[i];
//                 if(nrow>=0 && ncol<grid.size() && ncol>=0 && ncol<grid[0].size()
//                   && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
//                     vis[nrow][ncol] = 1;
//                     q.push({nrow,ncol});
//                 }
                    
//             }
//         }
//     }
    int numIslands(vector<vector<char>>& grid) {
     //    int numIslands = 0;
     //   int n = grid.size();
     // int m = grid[0].size();
     //    vector<vector<int>>vis(n, vector<int>(m,0));
     //    for(int i=0; i<n; i++){
     //        for(int j=0; j<m; j++){
     //            if(!vis[i][j] && grid[i][j] == '1'){
     //                numIslands++;
     //                bfs(i, j, vis, grid);
     //            }
     //        }
     //    }
     //    return numIslands;
        int row = grid.size();
        if (row==0) return 0;
        int col = grid[0].size();
        
        int res=0;
        
        vector<vector<bool> > mark(row, vector<bool>(col,true));
        
        queue<int> q_row;
        queue<int> q_col;
        
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (grid[i][j]=='1' && mark[i][j]){
                    q_row.push(i);
                    q_col.push(j);
                    mark[i][j] = false;
                    while (!q_row.empty()){
                        int ii = q_row.front();
                        int jj = q_col.front();
                        
                        if (ii+1<row && grid[ii+1][jj]=='1' && mark[ii+1][jj]){
                            q_row.push(ii+1);
                            q_col.push(jj);
                            mark[ii+1][jj] = false;
                        }
                        if (jj+1<col && grid[ii][jj+1]=='1' && mark[ii][jj+1]){
                            q_row.push(ii);
                            q_col.push(jj+1);
                            mark[ii][jj+1] = false;
                        }
                        if (ii-1 >=0 && grid[ii-1][jj]=='1' && mark[ii-1][jj]){
                            q_row.push(ii-1);
                            q_col.push(jj);
                            mark[ii-1][jj] = false;
                        }
                        if (jj-1>=0 && grid[ii][jj-1]=='1' && mark[ii][jj-1]){
                            q_row.push(ii);
                            q_col.push(jj-1);
                            mark[ii][jj-1] = false;
                        }
                        
                        q_row.pop();
                        q_col.pop();
                    }
                    res += 1;
                }
            }
        }
        return res;
    }
};