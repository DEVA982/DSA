class Solution {
public:
    void f(int ind,vector<int>& candidates, int target, vector<int>& ds , vector<vector<int>>& ans){
        int n = candidates.size();
        if(target==0) {
            ans.push_back(ds);
            return;
        
        }
        for(int i = ind ; i<n ;i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            f(i+1,candidates,target-candidates[i],ds,ans);
            ds.pop_back();
        }
        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,candidates,target,ds,ans);
        
        return ans;
        
    }
};