class Solution {
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> ans;

        function<void(int)> solve = [&](int node) {
            visited[node] = 1;
            ans.push_back(node);

            for(int next : adj[node]) {
                if(!visited[next]) {
                    solve(next);
                }
            }
        };

        solve(0);
        return ans;
    }
};