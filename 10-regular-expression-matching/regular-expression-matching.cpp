class Solution {
public:

    bool solve(string &s, string &p, int i, int j) {

        // Pattern finished
        if (j == p.size()) {
            return i == s.size();
        }

        // Is current character matching?
        bool firstMatch = false;

        if (i < s.size() &&
            (s[i] == p[j] || p[j] == '.')) {
            firstMatch = true;
        }

        // Next character is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {

            // Option 1: use zero occurrences
            bool skip = solve(s, p, i, j + 2);

            // Option 2: use one/more occurrences
            bool take = firstMatch &&
                        solve(s, p, i + 1, j);

            return skip || take;
        }

        // Normal character / '.'
        return firstMatch &&
               solve(s, p, i + 1, j + 1);
    }

    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};