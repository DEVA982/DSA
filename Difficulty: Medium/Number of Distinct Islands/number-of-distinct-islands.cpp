class Solution {
public:

    void solve(int i, int j,
               vector<vector<char>>& grid,
               vector<vector<int>>& flag,
               vector<vector<int>>& sol,
               int basei, int basej) {

        int n = grid.size();
        int m = grid[0].size();

        flag[i][j] = 1;

        // Store relative position
        sol.push_back({i - basei, j - basej});

        int dirs[4][2] = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        for(auto dir : dirs) {

            int ci = i + dir[0];
            int cj = j + dir[1];

            if(ci < 0 || ci >= n || cj < 0 || cj >= m)
                continue;

            if(flag[ci][cj] == 1 || grid[ci][cj] == 'W')
                continue;

            solve(ci, cj, grid, flag, sol, basei, basej);
        }
    }

    int countDistinctIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> flag(n, vector<int>(m, 0));

        // Each island shape will be stored here
        set<vector<vector<int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 'L' && flag[i][j] == 0) {

                    vector<vector<int>> sol;

                    // (i,j) is the starting point
                    solve(i, j, grid, flag, sol, i, j);

                    st.insert(sol);
                }
            }
        }

        return st.size();
    }
};
