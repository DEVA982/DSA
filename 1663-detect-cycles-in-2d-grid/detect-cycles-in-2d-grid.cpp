class Solution {
public:
    
    bool bfs(int i , int j , vector<vector<char>>& grid , vector<vector<int>> &flag ){
        int m = grid.size();
        int n = grid[0].size();
        flag[i][j]=1;
        queue<pair<pair<int,int>,pair<int,int>>> q;
        q.push({{i,j},{-1,-1}});
        while(!q.empty()){
            auto curr = q.front();
            int x = curr.first.first;
            int y = curr.first.second;

            int px = curr.second.first;
            int py = curr.second.second;
            q.pop();
            int dirs[4][2]={{0,-1},{0,+1},{-1,0},{+1,0}};
            for(auto dir : dirs){
                int ci = x+dir[0];
                int cj = y+dir[1];
                if(ci<0 || ci>=m || cj<0 || cj>=n) continue;
                if(grid[x][y]!=grid[ci][cj]) continue;
                if(ci==px && cj==py) continue;
                if(flag[ci][cj]) return true;
                flag[ci][cj]=1;
                q.push({{ci,cj},{x,y}});
            }

        }
        return false;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>flag(m,vector<int>(n,0));
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(flag[i][j]==0){
                    if(bfs(i,j,grid,flag)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};