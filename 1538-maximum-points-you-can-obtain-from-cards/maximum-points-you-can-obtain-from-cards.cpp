class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum = 0;
        for(int i = 0 ; i<k ; i++){
            lsum = lsum + nums[i];
        }
        int rsum = 0 ;
        int maxi = lsum;
        int r = nums.size()-1;
        for(int j = k -1 ; j>=0 ; j--){
            lsum = lsum - nums[j];
            rsum = rsum+nums[r];
            r--;
            maxi = max(maxi,lsum+rsum);

        }
        return maxi;
    }
};