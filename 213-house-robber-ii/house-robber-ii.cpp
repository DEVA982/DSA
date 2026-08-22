class Solution {
public:
    int solve(vector<int>& nums, int ind, int end,vector<int>& dp) {
        if(ind > end) {
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];

        int rob = nums[ind] + solve(nums, ind + 2, end,dp);
        int not_rob = solve(nums, ind + 1, end,dp);

        return dp[ind]=max(rob, not_rob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }
        vector<int>dp1(n,-1);
        

        // Don't rob last
        int case1 = solve(nums, 0, n - 2,dp1);

        // Don't rob first
        vector<int>dp2(n,-1);
        int case2 = solve(nums, 1, n - 1,dp2);

        return max(case1, case2);
    }
};