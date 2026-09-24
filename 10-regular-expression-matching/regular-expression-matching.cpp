class Solution {
public:

    vector<vector<int>> dp;

    bool solve(string &s, string &p, int i, int j) {

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Pattern finished
        if (j == p.size()) {
            return dp[i][j] = (i == s.size());
        }

        // Does current character match?
        bool firstMatch = false;

        if (i < s.size() &&
            (s[i] == p[j] || p[j] == '.')) {
            firstMatch = true;
        }

        // Next pattern character is *
        if (j + 1 < p.size() && p[j + 1] == '*') {

            // Option 1: zero occurrences
            bool skip = solve(s, p, i, j + 2);

            // Option 2: use current character
            bool take = firstMatch &&
                        solve(s, p, i + 1, j);

            return dp[i][j] = skip || take;
        }

        // Normal character or '.'
        return dp[i][j] =
            firstMatch && solve(s, p, i + 1, j + 1);
    }

    bool isMatch(string s, string p) {

        dp.assign(s.size() + 1,
                  vector<int>(p.size() + 1, -1));

        return solve(s, p, 0, 0);
    }
};