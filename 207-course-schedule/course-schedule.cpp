class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {

        // node is already in current DFS path
        if (visited[node] == 1)
            return false;

        // completely processed
        if (visited[node] == 2)
            return true;

        visited[node] = 1;

        for (auto next : adj[node]) {
            if (!dfs(next, adj, visited))
                return false;
        }

        // DFS for this node is completely finished
        visited[node] = 2;

        return true;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n);

        for (auto edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
        }

        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited))
                    return false;
            }
        }

        return true;
    }
};