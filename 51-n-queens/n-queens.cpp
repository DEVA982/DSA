class Solution {
public:
    bool qcheck(int row,int col ,vector<string> &board , int n){
        int digrow = row;
        int digcol=col;
        while(digrow>=0 && digcol>=0){
            if(board[digrow][digcol]=='Q') return false;
            digrow--;
            digcol--;
        }
        digrow = row;
        digcol=col;
        while(digrow>=0 && digcol<n){
            if(board[digrow][digcol]=='Q') return false;
            digrow--;
            digcol++;
        }
        digrow=row;
        while(digrow>=0){
            if(board[digrow][col]=='Q') return false;
            digrow--;
        }
        return true;


    }
    void solve(int row ,vector<vector<string>> &ans, vector<string> &board , int n){
        if(row==n){
            ans.push_back(board);
            return ;
        }
        for(int col = 0 ; col<n ; col++){
            if(qcheck(row,col,board,n)){
                board[row][col]='Q';
                solve(row+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0 ; i<n ; i++){
            board[i]=s;
        }
        solve(0,ans,board,n);
        return ans;
        
    }
};