class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>count(n,1);
        vector<int>dp(n,1);
        //int maxi=0;
        for(int i = 1;i<n;i++){
            for(int prev = 0 ; prev<i;prev++){
                if(nums[i]>nums[prev]){
                    if(dp[i]<dp[prev]+1){
                        dp[i]=dp[prev]+1;
                        count[i]=count[prev];
                    }
                    else if(dp[i]==dp[prev]+1){
                        count[i] += count[prev];
                    }
                }
            }
            
            
        }
        int max_value=*max_element(dp.begin(),dp.end());
        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            if(dp[i]==max_value){
                ans+=count[i];
            }

        }
        return ans;
        
    }
};