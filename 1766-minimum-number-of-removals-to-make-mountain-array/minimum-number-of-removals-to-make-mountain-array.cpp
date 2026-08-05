class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp1(n, 1); // LIS from left
        vector<int> dp2(n, 1); // LIS from right

        // LIS from left
        for (int i = 1; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev] && dp1[i] < dp1[prev] + 1) {
                    dp1[i] = dp1[prev] + 1;
                }
            }
        }

        // LIS from right
        for (int i = n - 2; i >= 0; i--) {
            for (int next = n - 1; next > i; next--) {
                if (nums[i] > nums[next] && dp2[i] < dp2[next] + 1) {
                    dp2[i] = dp2[next] + 1;
                }
            }
        }

        int longestMountain = 0;

        for (int i = 1; i < n - 1; i++) {
            // A valid mountain needs both increasing and decreasing parts
            if (dp1[i] > 1 && dp2[i] > 1) {
                longestMountain = max(longestMountain,
                                      dp1[i] + dp2[i] - 1);
            }
        }

        return n - longestMountain;
    }
};