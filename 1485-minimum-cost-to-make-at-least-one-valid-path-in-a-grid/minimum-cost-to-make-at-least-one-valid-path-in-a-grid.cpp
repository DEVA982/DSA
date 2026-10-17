
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<
            pair<pair<int,int>,pair<int,int>>,
            vector<pair<pair<int,int>,pair<int,int>>>,
            greater<pair<pair<int,int>,pair<int,int>>>
        > pq;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        pq.push({{0, grid[0][0]}, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int r = it.second.first;
            int c = it.second.second;
            int ans = it.first.first;
            int curr = it.first.second;

            if (ans > dist[r][c]) continue;

            if (r == n - 1 && c == m - 1) {
                return ans;
            }

            // Right
            if (c + 1 < m) {
                int cost = ans + (curr == 1 ? 0 : 1);
                if (cost < dist[r][c + 1]) {
                    dist[r][c + 1] = cost;
                    pq.push({{cost, grid[r][c + 1]}, {r, c + 1}});
                }
            }

            // Left
            if (c - 1 >= 0) {
                int cost = ans + (curr == 2 ? 0 : 1);
                if (cost < dist[r][c - 1]) {
                    dist[r][c - 1] = cost;
                    pq.push({{cost, grid[r][c - 1]}, {r, c - 1}});
                }
            }

            // Down
            if (r + 1 < n) {
                int cost = ans + (curr == 3 ? 0 : 1);
                if (cost < dist[r + 1][c]) {
                    dist[r + 1][c] = cost;
                    pq.push({{cost, grid[r + 1][c]}, {r + 1, c}});
                }
            }

            // Up
            if (r - 1 >= 0) {
                int cost = ans + (curr == 4 ? 0 : 1);
                if (cost < dist[r - 1][c]) {
                    dist[r - 1][c] = cost;
                    pq.push({{cost, grid[r - 1][c]}, {r - 1, c}});
                }
            }
        }

        return -1;
    }
};
