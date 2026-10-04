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
            q.push(i);
            ans[i]=0;
            while(q.size()>0){
                int node = q.front();
                q.pop();
                for(auto adjNode:graph[node]){
                    if(ans[adjNode]==-1){
                        ans[adjNode]=!ans[node];
                        q.push(adjNode);
                    }
                    else if(ans[adjNode]==ans[node]){
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
};