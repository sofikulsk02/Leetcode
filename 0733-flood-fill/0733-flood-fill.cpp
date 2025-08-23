class Solution {
public:
   void dfs(vector<vector<int>>& image,vector<vector<int>>& ans,int sr,int sc,int color,int initialColor){
    ans[sr][sc]=color;
    int delRow []={-1,0,1,0};
    int delCol []={0,1,0,-1};
    int n=image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++){
        int nrow=sr+delRow[i];
        int ncol=sc+delCol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialColor && ans[nrow][ncol]!=color){
                    dfs(image,ans,nrow,ncol,color,initialColor);
        }
    }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int initialColor=image[sr][sc];
        dfs(image,ans,sr,sc,color,initialColor);
        return ans;
    }
};