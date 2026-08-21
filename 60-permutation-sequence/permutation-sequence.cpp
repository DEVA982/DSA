class Solution {
public:
    bool solve(vector<int>& visited, string& s,
               int n, int ind, int& count, int k, string& ans) {

        if (ind == n + 1) {

            count++;

            if (count == k) {
                ans = s;
                return true;   // kth permutation found
            }

            return false;
        }

        for (int a = 1; a <= n; a++) {

            if (visited[a] == 0) {

                visited[a] = 1;
                s.push_back('0' + a);

                if (solve(visited, s, n, ind + 1, count, k, ans))
                    return true;

                s.pop_back();
                visited[a] = 0;
            }
        }

        return false;
    }

    string getPermutation(int n, int k) {

        vector<int> visited(n + 1, 0);
        string s;
        string ans;

        int count = 0;

        solve(visited, s, n, 1, count, k, ans);

        return ans;
    }
};