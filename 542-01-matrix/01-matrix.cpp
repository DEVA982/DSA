class Solution {
public:

    

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<vector<int>>flag(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0 ; i<m ;i++){
            for(int j = 0 ; j< n ; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});

                    flag[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first.first;
            int j = curr.first.second;
            int sol = curr.second;
            
            ans[i][j] = sol;
            int dirs[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
            for(auto dir : dirs){
                int mi = i+dir[0];
                int mj = j+dir[1];
                if(mi<0 || mi>=m || mj<0 || mj>=n) continue;
                if(flag[mi][mj]==1 ) continue;
                q.push({{mi,mj},sol+1});
                flag[mi][mj]=1;
            }

        }
        return ans;
        
        
    }
};