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
        }
        auto max_iindex = max_element(dp.begin(),dp.end());
        int max_index = max_iindex-dp.begin();
        cout<<max_index<<endl;
        for(auto a : hash) cout<<a<<endl;

        vector<int>ans;
        while(max_index>=0){
            if(max_index==0){
                ans.push_back(nums[max_index]);
                max_index--;
            }
            else{
                ans.push_back(nums[max_index]);
                if(max_index==hash[max_index]){
                    max_index=-1;
                }
                else{
                    max_index=hash[max_index];
                }

            }
            
            
        }
        return ans;
        
    }
};