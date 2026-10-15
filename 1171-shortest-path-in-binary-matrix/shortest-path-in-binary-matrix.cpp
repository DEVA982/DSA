
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        dp[0][0] = 1;
        q.push({0,0});

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(i == n-1 && j == n-1)
                return dp[i][j];

            for(int a = -1; a <= 1; a++) {
                for(int b = -1; b <= 1; b++) {
                    if(a == 0 && b == 0) continue;

                    int x = i + a;
                    int y = j + b;

                    if(x < 0 || y < 0 || x >= n || y >= n)
                        continue;

                    if(grid[x][y] == 1) continue;

                    if(dp[x][y] > dp[i][j] + 1) {
                        dp[x][y] = dp[i][j] + 1;
                        q.push({x,y});
                    }
                }
            }
        }

        return -1;
    }
};
