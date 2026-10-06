class Solution {
public:

    

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> flag(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    flag[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int sol = q.front().second;
            q.pop();
            vector<int> p1 = {1,-1,0,0};
            vector<int>p2={0,0,1,-1};
            ans[i][j]=sol;
            for(int k = 0 ; k<4;k++){
                if(i+p1[k]>=m || j+p2[k]>=n) continue;
                if(i+p1[k]<0 || j+p2[k]<0) continue;
                if(flag[i+p1[k]][j+p2[k]]==1) continue;
                q.push({{i+p1[k],j+p2[k]},sol+1});
                flag[i+p1[k]][j+p2[k]]=1;
            }

        }
        return ans;
    }
};