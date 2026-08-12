class Solution {
public:
    void dfs(int i  , int j ,vector<vector<char>>& board,vector<vector<int>>& flag ){
        int m = board.size();
        int n = board[0].size();
        flag[i][j]=1;
        int dirs[4][2]={{-1,0},{+1,0},{0,-1},{0,+1}};
        for(auto dir: dirs){
            int ci = i+dir[0];
            int cj = j+dir[1];
            if(ci<0 || ci>=m || cj<0 || cj>=n) continue;
            if(flag[ci][cj]==1 || board[ci][cj]!='O') continue;
            dfs(ci,cj,board,flag); 
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> flag(m,vector<int>(n,0));
        for(int i = 0 ; i<m ; i++){
            if(board[i][0]=='O' && flag[i][0]==0) dfs(i,0,board,flag);
            if(board[i][n-1]=='O'&& flag[i][n-1]==0)dfs(i,n-1,board,flag);
        }

        for(int j = 0 ; j<n ; j++){
            if(board[0][j]=='O' && flag[0][j]==0) dfs(0,j,board,flag);
            if(board[m-1][j]=='O'&& flag[m-1][j]==0)dfs(m-1,j,board,flag);
        }
        for (int i = 0 ; i<m ; i++){
            for (int j = 0 ; j< n ; j++){
                if(board[i][j]=='O' && flag[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};