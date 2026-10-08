class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {

        // node is already in current DFS path
        if(visited[node]==1){
            return false;
        }
        if(visited[node]==2){
            return true;
        }
        visited[node]=1;
        for(auto adjNode:adj[node]){
            if(!dfs(adjNode,adj,visited)){
                return false;
            }
        }
        visited[node]=2;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n);
        vector<int>indegree(n);

        for (auto edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];
            indegree[edge[1]]++;

            adj[course].push_back(prerequisite);
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
            return false;
        }

        return true;
    }
};