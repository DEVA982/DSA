class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        queue <pair<int,int>>q;
        vector<vector<int>> flag(m,vector<int>(n,0));
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(flag[i][j]==0 && grid[i][j]==2){
                    
                    q.push({i,j});
                
                }
            }
        }
        //int ans = 0;
        vector<int> a = { 0,0,-1,+1};
        vector<int> b = {-1,+1,0,0};
        while(!q.empty()){
            int size = q.size();
            for(int x = 0 ; x<size ; x++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++) {

                    int row = i + a[k];
                    int col = j + b[k];

                    if(row >= 0 && row < m &&
                       col >= 0 && col < n &&
                       grid[row][col] == 1) {

                        grid[row][col] = 2;
                        q.push({row, col});
                    }
                }

            }
             if(!q.empty())
                ans++;
        }

         for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return ans;

        
    }
};