class Solution {
public:
    bool dfs(int ind,vector<vector<int>> &adj ,vector<int> &flag ,vector<int> &path , vector<int> &check ){
        flag[ind]=1;
        path[ind]=1;
        for(auto node : adj[ind]){
            if(flag[node]==0){
                if(dfs(node,adj,flag,path,check)){
                    return true;
                }
            }
            else if(path[node]==1){
                return true;
            }
        }
        path[ind]=0;
        check[ind]=1;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>flag(n,0);
        vector<int>path(n,0);
        vector<int> check(n,0);
        for(int i = 0 ; i<n ; i++){
            if(flag[i]==0){
                dfs(i,graph,flag,path,check);
            }
        }
        vector<int>ans;
        for(int i = 0; i<n ; i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
        
        
    }
};