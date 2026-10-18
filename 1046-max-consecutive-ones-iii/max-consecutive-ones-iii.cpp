class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0 ;
        int n = nums.size();
        int ans = 0;
        int count = 0;
        while(right<n){
            if(nums[right]==1){
                ans = max(ans,right-left+1);
                right++;
            }
            else if(nums[right]==0 && count<k){
                ans = max(ans,right-left+1);
                right++;
                count++;

            }
            else{
                if(nums[left]==0){
                    
                    count--;
                }
                left++;
                
            }
        }
        return ans;
        
    }
};