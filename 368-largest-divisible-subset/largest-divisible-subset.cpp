class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        vector<int> dp(n,1);
        vector<int>hash(n);
        hash[0]=0;
        int maxi = 0;
        for(int i = 1 ; i<nums.size() ; i++){
            hash[i]=i;
            for(int prev = 0 ; prev<i ; prev++){
                if((nums[i]%nums[prev]==0 || nums[prev]%nums[i]==0 ) && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
                
            }
            if(dp[i]>dp[maxi]) maxi = i;
        }
        

        vector<int>ans;
        while(hash[maxi] != maxi){
            ans.push_back(nums[maxi]);
            maxi = hash[maxi];
        }
         ans.push_back(nums[maxi]);
        return ans;
        
    }
};