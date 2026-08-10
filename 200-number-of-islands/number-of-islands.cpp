class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<int>>& flag) {

        flag[i][j] = 1;

        int m = grid.size();
        int n = grid[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {

            int ni = i + dr[k];
            int nj = j + dc[k];

            if(ni >= 0 && ni < m &&
               nj >= 0 && nj < n &&
               grid[ni][nj] == '1' &&
               flag[ni][nj] == 0) {

                dfs(ni, nj, grid, flag);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> flag(m, vector<int>(n, 0));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '1' && flag[i][j] == 0) {

                    ans++;

                    dfs(i, j, grid, flag);
                }
            }
        }

        return ans;
    }
};