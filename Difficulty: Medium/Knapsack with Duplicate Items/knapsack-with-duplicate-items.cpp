class Solution {
  public:
    int solve(vector<int>& val, vector<int>& wt, int capacity , int ind , vector<vector<int>>&dp){
        int n = val.size();
        if(ind==n){
            return 0;
        }
        if(dp[ind][capacity]!=-1) return dp[ind][capacity];
        int notTake = solve(val,wt,capacity,ind+1,dp);
        int take = 0;
        if(capacity>=wt[ind]){
            take = val[ind]+solve(val,wt,capacity-wt[ind],ind,dp);
        }
        return dp[ind][capacity]=max(take,notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        // code here
        vector<vector<int>>dp(val.size(),vector<int>(capacity+1,-1));
        return solve(val,wt,capacity,0,dp);
        
    }
};