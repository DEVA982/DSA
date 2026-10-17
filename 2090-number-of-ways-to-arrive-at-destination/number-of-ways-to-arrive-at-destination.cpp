
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> dp(n, 0);

        long long mod = 1e9 + 7;
        dist[0] = 0;
        dp[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            long long d = it.first;
            int parent = it.second;

            if(d != dist[parent]) continue;

            for(auto next : adj[parent]) {
                int node = next.first;
                int wt = next.second;

                if(dist[node] > dist[parent] + wt) {
                    dist[node] = dist[parent] + wt;
                    dp[node] = dp[parent];

                    pq.push({dist[node], node});
                }
                else if(dist[node] == dist[parent] + wt) {
                    dp[node] = (dp[node] + dp[parent]) % mod;
                }
            }
        }

        return dp[n-1];
    }
};
