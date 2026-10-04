class Solution {
public:
    int timer =1;
    void dfs(vector<vector<int>>&adj ,int parent,int node , vector<int>&low ,vector<int> &tin,
    vector<int>&visited , vector<vector<int>>&bridges ){
        visited[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto next : adj[node]){
            if(next==parent){
                continue;
            }
            if(visited[next]==0){
                dfs(adj,node,next,low,tin,visited,bridges);
                low[node]=min(low[node],low[next]);
                if(tin[node]<low[next]){
                    bridges.push_back({node,next});
                }
            }
            else{
                low[node]=min(low[node],low[next]);
            }

        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> tin(n);
        vector<int>low(n);
        vector<int> visited(n,0);
        vector<vector<int>>bridges;
        dfs(adj,-1,0,low,tin,visited,bridges);
        return bridges;

    }
};