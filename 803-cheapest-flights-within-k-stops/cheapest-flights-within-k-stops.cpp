
class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(V);

        for(auto edge : flights) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adj[start].push_back({weight, end});
        }

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0, {src, 0}});

        vector<vector<int>> dist(V, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int cost = it.first;
            int node = it.second.first;
            int stops = it.second.second;

            if(node == dst) return cost;

            if(stops == k + 1) continue;

            for(auto next : adj[node]) {
                int node2 = next.second;
                int wt = next.first;

                if(dist[node2][stops + 1] > cost + wt) {
                    dist[node2][stops + 1] = cost + wt;
                    pq.push({cost + wt, {node2, stops + 1}});
                }
            }
        }

        return -1;
    }
};
