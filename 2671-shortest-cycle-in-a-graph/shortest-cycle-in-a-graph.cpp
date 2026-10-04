class Solution {
public:
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int start = edge[0];
            int end = edge[1];
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        int ans = INT_MAX;
        for(int start = 0 ; start<n;start++){
            vector<int>dist(n,-1);
            vector<int> parent(n,-1);
            
            queue<int> q;
            q.push(start);
            dist[start]=0;
            while(q.size()>0){
                int node = q.front();
                q.pop();
                for(auto next: adj[node]){
                    if(dist[next]==-1){
                        dist[next]=dist[node]+1;
                        parent[next]=node;
                        q.push(next);
                    }
                    else if(parent[node]!=next){
                        int curr = dist[node]+dist[next]+1;
                        //cout<<curr<<endl;
                        ans = min (ans,curr);
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
        


        
    }
};