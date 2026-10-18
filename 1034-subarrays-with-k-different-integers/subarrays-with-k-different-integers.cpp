class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k<=0) return 0;
        int left = 0; 
        int right = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        int cnt = 0;
        while(right<n){
            mp[nums[right]]++;
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            cnt = cnt+right-left+1;
            right++;
        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a1 = solve(nums,k);
        int a2=solve(nums,k-1);
        return a1-a2;
        
    }
};