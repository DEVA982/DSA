
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        if(grid[0][0]==1) return -1;
        dist[0][0]=1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int row = it.second.first;
            int col = it.second.second;
            int d = it.first;
            if(row == n-1 && col==n-1){
                return d;
            }
            for(int i = -1 ; i<=1 ;i++){
                for(int j = -1 ; j<=1 ; j++){
                    if(i==0 && j==0)continue;
                    if(row+i>=n || col+j>=n ) continue;
                    if(row+i<0 || col+j<0) continue;
                    if(grid[row+i][col+j]==1) continue;
                    if(dist[row+i][col+j]>dist[row][col]+1){
                        dist[row+i][col+j]=dist[row][col]+1;
                        pq.push({dist[row+i][col+j],{row+i,col+j}});
                    }

                }
            }
           
        }
         return -1;
    }
};
