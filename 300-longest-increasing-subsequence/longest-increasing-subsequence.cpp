// memoization solution
class Solution {
public:
    int f(vector<int>& nums ,int ind , int prev, vector<vector<int>> &dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=INT_MIN) return dp[ind][prev+1];

        int not_take = f(nums,ind+1,prev,dp);
        int take = 0;
        
        if(prev==-1){
            take = 1+f(nums,ind+1,ind,dp);
        }
        else if(nums[prev]<nums[ind]){
            take = 1+f(nums,ind+1,ind,dp);
        }
        return dp[ind][prev+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind = n-1; ind>=0 ; ind-- ){
            for(int prev = ind-1 ; prev>=-1; prev--){
                int not_take = dp[ind+1][prev+1];
                int take = 0;
                if(prev==-1||nums[prev]<nums[ind]){
                    take = 1+dp[ind+1][ind+1];

                }
                dp[ind][prev+1]=max(take,not_take);
                

            }
        }
        
        return dp[0][-1+1];//(nums,0,prev,dp);

        
    }
};