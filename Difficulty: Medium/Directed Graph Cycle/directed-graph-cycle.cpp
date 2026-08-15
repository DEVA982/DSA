class Solution {
  public:
    bool dfs(int ind,vector<vector<int>> &adj ,vector<int> &flag ,vector<int> &path ){
        flag[ind]=1;
        path[ind]=1;
        for(auto node : adj[ind]){
            if(flag[node]==0){
                if(dfs(node,adj,flag,path)){
                    return true;
                }
            }
            else if(path[node]==1){
                return true;
            }
        }
        path[ind]=0;
        return false;
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>> adj(V);
        vector<int> flag(V,0);
        vector<int> path(V,0);
        
        for(int i = 0 ; i<edges.size() ;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i = 0 ; i<V ; i++){
            if(flag[i]==0){
                if(dfs(i,adj,flag,path)){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};