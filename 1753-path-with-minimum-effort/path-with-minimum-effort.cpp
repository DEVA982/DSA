
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> diff(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> q;

        q.push({0, {0, 0}});
        diff[0][0] = 0;

        vector<int> a1 = {0, 0, 1, -1};
        vector<int> b1 = {1, -1, 0, 0};

        while(!q.empty()) {
            auto it = q.top();
            q.pop();

            int ht = it.first;
            int r1 = it.second.first;
            int c1 = it.second.second;

            if(r1 == n-1 && c1 == m-1)
                return ht;

            if(diff[r1][c1] != ht) continue;

            for(int k = 0; k < 4; k++) {
                int x = r1 + a1[k];
                int y = c1 + b1[k];

                if(x >= n || y >= m || x < 0 || y < 0)
                    continue;

                int val = abs(heights[x][y] - heights[r1][c1]);
                int newDiff = max(ht, val);

                if(diff[x][y] > newDiff) {
                    diff[x][y] = newDiff;
                    q.push({newDiff, {x, y}});
                }
            }
        }

        return -1;
    }
};
