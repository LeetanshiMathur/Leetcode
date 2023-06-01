class Solution {
public:
   void dfs(vector<vector<int>>&image,int r,int c,int color,int original){
        image[r][c] = color;
       int drow[] = {-1,0,1,0};
       int dcol[] = {0,1,0,-1};
       for(int i=0; i<4; i++){
           int row = r + drow[i];
           int col = c + dcol[i];
           if(row>=0 && row<image.size() && col>=0 && col<image[0].size() && image[row]            [col]==original){
               dfs(image,row,col,color,original);
           }
       }
   
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if( image.size()==0 || image[0].size()==0 || image[sr][sc] == color) 
            return image;
        int original = image[sr][sc];
       dfs (image , sr, sc, color, original);
        return image;
    }
};