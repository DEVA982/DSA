class Solution {
public:
    void dfs(int i  , int j ,vector<vector<int>>& grid,vector<vector<int>>& flag ){
        int m = grid.size();
        int n = grid[0].size();
        flag[i][j]=1;
        int dirs[4][2]={{-1,0},{+1,0},{0,-1},{0,+1}};
        for(auto dir: dirs){
            int ci = i+dir[0];
            int cj = j+dir[1];
            if(ci<0 || ci>=m || cj<0 || cj>=n) continue;
            if(flag[ci][cj]==1 || grid[ci][cj]!=1) continue;
            dfs(ci,cj,grid,flag); 
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> flag(m,vector<int>(n,0));
        for(int i = 0 ; i<m ; i++){
            if(grid[i][0]==1 && flag[i][0]==0) dfs(i,0,grid,flag);
            if(grid[i][n-1]==1&& flag[i][n-1]==0)dfs(i,n-1,grid,flag);
        }

        for(int j = 0 ; j<n ; j++){
            if(grid[0][j]==1 && flag[0][j]==0) dfs(0,j,grid,flag);
            if(grid[m-1][j]==1&& flag[m-1][j]==0)dfs(m-1,j,grid,flag);
        }
        int ans = 0;
        for (int i = 0 ; i<m ; i++){
            for (int j = 0 ; j< n ; j++){
                if(grid[i][j]==1 && flag[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};