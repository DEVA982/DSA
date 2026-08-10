class Solution {
public:
    void dfs(int node ,vector<vector<int>>& adj,vector<int> &flag ){
        flag[node]=1;
        int n = adj.size();
        for(int j = 0 ; j<n ; j++){
            if((node!=j)&&(adj[node][j]==1)&&(flag[j]==0)){
                dfs(j,adj,flag);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> flag(n,0);
        int ans=0;
        for(int i = 0 ;i < n ; i++){
            if(flag[i]==0){
                dfs(i,adj,flag);
                ans++;
            }
        }
        return ans;
        
    }
};