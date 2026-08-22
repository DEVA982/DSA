class Solution {
public:
    int solve(vector<int>&nums , int ind , int sum , vector<vector<int>>&dp){
        int n = nums.size();
        if(ind==n){
            if(sum==0) return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int not_take = solve(nums,ind+1,sum,dp);
        int take = 0 ;
        if(sum>=nums[ind]){
            take=solve(nums,ind+1,sum-nums[ind],dp);
        }
        return dp[ind][sum]=max(take,not_take);

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            sum+=num;
        }
        
        if(sum%2==1) return false;
        sum = sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        int ans= solve(nums,0,sum,dp);
        return ans;
        
    }
};