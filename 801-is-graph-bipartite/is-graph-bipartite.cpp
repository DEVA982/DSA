class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans(n,-1);
        for(int i = 0 ; i<n ; i++){
            if(ans[i]!=-1){
                continue;
            }
            queue<int> q;
            ans[i]=0;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto adj : graph[node]){
                    if(ans[adj]==-1){
                        ans[adj]=!(ans[node]);
                        q.push(adj);
                    }
                    else if(ans[adj] == ans[node]){
                        return false;
                    }

                }
            }
        }
        return true;
        
    }
};