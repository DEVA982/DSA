class Solution {
public:

    int solve(vector<int>& rods, int ind, int diff,
              vector<vector<int>>& dp) {

        if (ind == rods.size()) {
            if (diff == 0)
                return 0;

            return -1000000000;
        }

        if (dp[ind][diff] != -1)
            return dp[ind][diff];

        // Don't take
        int notTake = solve(
            rods, ind + 1, diff, dp
        );

        // Put rod on the taller side
        int taller = solve(
            rods,
            ind + 1,
            diff + rods[ind],
            dp
        );

        // Put rod on the shorter side
        int shorter = solve(
            rods,
            ind + 1,
            abs(diff - rods[ind]),
            dp
        );

        // When rod is placed on shorter side,
        // min(diff, rod) contributes to equal height
        shorter += min(diff, rods[ind]);

        return dp[ind][diff] =
            max({notTake, taller, shorter});
    }

    int tallestBillboard(vector<int>& rods) {

        int sum = 0;

        for (int x : rods)
            sum += x;

        vector<vector<int>> dp(
            rods.size(),
            vector<int>(sum + 1, -1)
        );

        return solve(rods, 0, 0, dp);
    }
};