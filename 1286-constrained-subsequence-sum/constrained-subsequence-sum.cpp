class Solution {
public:
    
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int>dp(nums.size(),0);
        deque<int> dq;
        int ans = nums[0];
        for(int i = 0 ;i <nums.size();i++){
            while( dq.size()>0 && dq.front()<i-k){
                dq.pop_front();
            }
            dp[i]=nums[i];
            if(dq.size()>0){
                dp[i]=max(dp[i],dp[i]+dp[dq.front()]);
            }
            ans = max(ans,dp[i]);
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans;
    }
};