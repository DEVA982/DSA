class Solution {
  public:
    void solve(int row , int col ,vector<vector<int>>& maze ,vector<vector<int>> &visited, vector<string> &ans,string&s){
        int n = maze.size();
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        if(maze[row][col]!=1) return;
        visited[row][col]=1;
       
        if(row+1<n && maze[row+1][col]==1 && visited[row+1][col]==0) {
            visited[row+1][col]=1;
            s.push_back('D');
            solve(row+1,col,maze,visited,ans,s);
            s.pop_back();
            visited[row+1][col]=0;
        }
        if(col-1>=0 && maze[row][col-1]==1 && visited[row][col-1]==0){
            visited[row][col-1]=1;
            s.push_back('L');
            solve(row,col-1,maze,visited,ans,s);
            s.pop_back();
            visited[row][col-1]=0;
        }
        if(col+1<n && maze[row][col+1]==1 && visited[row][col+1]==0) {
            s.push_back('R');
            visited[row][col+1]=1;
            solve(row,col+1,maze,visited,ans,s);
            visited[row][col+1]=0;
            s.pop_back();
        }
         if(row-1>=0 && maze[row-1][col]==1 && visited[row-1][col]==0) {
            s.push_back('U');
            visited[row-1][col]=1;
            solve(row-1,col,maze,visited,ans,s);
            s.pop_back();
            visited[row-1][col]=0;
        }
        
        
        
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        string s;
        vector<vector<int>> visited(maze.size(),vector<int>(maze.size(),0));
        solve(0,0,maze,visited,ans,s);
        
        return ans;
    }
};