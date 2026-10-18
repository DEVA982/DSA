
class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(V);

        for(auto edge : flights){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        >pq;
        vector<vector<int>>dist(V,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int node = it.second.first;
            int stops = it.second.second;
            if(node==dst) return d;
            if(stops+1>=k+2) continue;
            for(auto next : adj[node]){
                int node2 = next.first;
                int wt = next.second;
                if(dist[node2][stops+1]>dist[node][stops]+wt){
                    dist[node2][stops+1]=dist[node][stops]+wt;
                    pq.push({dist[node2][stops+1],{node2,stops+1}});
                }
            }
        }
        return -1;
    }
};
