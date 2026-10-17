class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(k + 1, INT_MAX))
        );

        dist[0][0][0] = 0;

        priority_queue<
            pair<pair<int,int>, pair<int,int>>,
            vector<pair<pair<int,int>, pair<int,int>>>,
            greater<pair<pair<int,int>, pair<int,int>>>
        > pq;

        pq.push({{0, 0}, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int val = it.first.first;
            int stops = it.first.second;
            int r = it.second.first;
            int c = it.second.second;

            // Skip outdated entries
            if (val > dist[r][c][stops]) continue;

            if (r == n - 1 && c == m - 1) {
                return val;
            }

            vector<int> a = {1, -1, 0, 0};
            vector<int> b = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++) {
                int nr = r + a[i];
                int nc = c + b[i];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                int newStops = stops + grid[nr][nc];

                if (newStops <= k &&
                    dist[nr][nc][newStops] > val + 1) {

                    dist[nr][nc][newStops] = val + 1;

                    pq.push({
                        {val + 1, newStops},
                        {nr, nc}
                    });
                }
            }
        }

        return -1;
    }
};