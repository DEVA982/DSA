class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int>indegree(n);

        for (auto edge : prerequisites) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;

            //adj[course].push_back(prerequisite);
        }
        queue<int>q;
        for(int i = 0 ;i<n ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            //cout<<node<<endl;
            topo.push_back(node);
            for(auto next : adj[node]){
                //cout<<indegree[next]<<endl;
                indegree[next]--;
                //cout<<indegree[next]<<endl;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        if(topo.size()!=n){
            return {};
        }
        reverse(topo.begin(),topo.end());
        return topo;
        
    }
};