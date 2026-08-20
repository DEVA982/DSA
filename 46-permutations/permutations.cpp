class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int>flag,vector<int>rec){
        int n = nums.size();
        if(rec.size()==nums.size()) {
            ans.push_back(rec);
            return ;

        }
        
        for(int i = 0 ; i<n ; i++){
            if(flag[i]!=0) continue;
            rec.push_back(nums[i]);
            flag[i]=1;
            solve(nums,ans,flag,rec);
            rec.pop_back();
            flag[i]=0;
            
        }
       
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>flag(nums.size(),0);
        vector<int>rec;
        solve(nums,ans,flag,rec);
        
        return ans;


        
    }
};