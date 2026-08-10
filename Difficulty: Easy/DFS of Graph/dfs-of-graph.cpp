class Solution {
public:
    void dfs(int node ,vector<vector<int>>& adj,vector<int> &ans,vector<int> &flag ){
        ans.push_back(node);
        flag[node]=1;
        for(int num:adj[node]){
            if(flag[num]==0){
                dfs(num,adj,ans,flag);
            }
        }
        
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        vector<int> flag(n);
        dfs(0,adj,ans,flag);
        return ans;
    }
};