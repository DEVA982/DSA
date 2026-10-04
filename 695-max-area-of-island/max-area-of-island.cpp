class Solution {
public:
    
    int dfs(int i , int j,int cnt ,vector<vector<int>>& grid,vector<vector<int>> &visited ){
        int n=grid.size();
        int m = grid[0].size();
        int area =1 ;
        
        visited[i][j]=1;
        vector<int> p1 = {1,-1,0,0};
        vector<int>p2={0,0,1,-1};
        for(int k = 0 ; k<4 ; k++){
            if(i+p1[k]>=n || j+p2[k]>=m){
                continue;
            }
            if(i+p1[k]<0 || j+p2[k]<0){
                continue;
            }
            if(grid[i+p1[k]][j+p2[k]]==0 || visited[i+p1[k]][j+p2[k]]==1){
                continue;
            }
            area=area+dfs(i+p1[k],j+p2[k],cnt,grid,visited);
        }
        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(visited[i][j]!=0|| grid[i][j]==0){
                    continue;
                }
                ans = max(ans,dfs(i,j,0,grid,visited));
            }
        }
        return ans;
        
    }
};