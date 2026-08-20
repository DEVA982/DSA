class Solution {
public:
    void solve(int ind,vector<int>& nums,vector<vector<int>> &ans,vector<int>flag,vector<int>rec){
        int n = nums.size();
        if(ind==n) {
            ans.push_back(rec);
            return ;

        }
        
        for(int i = 0 ; i<n ; i++){
            if(flag[i]!=0) continue;
            rec.push_back(nums[i]);
            flag[i]=1;
            solve(ind+1,nums,ans,flag,rec);
            rec.pop_back();
            flag[i]=0;
            
        }
       
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>flag(nums.size(),0);
        vector<int>rec;
        solve(0,nums,ans,flag,rec);
        
        return ans;


        
    }
};