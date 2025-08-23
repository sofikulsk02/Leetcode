class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++) {
                int nrow = r + drow[k];
                int ncol = c + dcol[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                   !vis[nrow][ncol] && grid[nrow][ncol]=='1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                if(!vis[row][col] && grid[row][col]=='1') {
                    bfs(row, col, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }
};
