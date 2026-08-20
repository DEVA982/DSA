class Solution {
public:
    bool numCheck(int row , int col ,vector<vector<char>>& board ,char num ){
        //row check
        for(int i = 0 ; i<9 ; i++){
            if(board[row][i]==num) return false;
        }
        // col check
        for(int j = 0 ; j< 9 ; j++){
            if(board[j][col]==num) return false;
        }
        int startrow = row - (row%3);
        int startcol = col - (col%3);
        for(int i = 0 ; i<3; i++){
            for(int j = 0; j<3 ; j++){
                if(board[i+startrow][j+startcol]==num) return false;
            }
        }
        return true;
    }
    bool correctSudoku(int row , int col ,vector<vector<char>>& board ){
        if(row==9) return true ;
        if(col==9){
            return correctSudoku(row + 1, 0, board);
        }
        if(board[row][col]!='.'){
            return correctSudoku(row,col+1,board);
        }
        vector<char> nums = {'1','2','3','4','5','6','7','8','9'};
        for(auto  num : nums){
            if(numCheck(row,col,board,num)){
                board[row][col]=num;
                if(correctSudoku( row ,col+1 ,board )) return true;
                board[row][col]='.';
            }
        }
        return false;

    }
    void solveSudoku(vector<vector<char>>& board) {
        correctSudoku(0, 0, board);
        
    }
};