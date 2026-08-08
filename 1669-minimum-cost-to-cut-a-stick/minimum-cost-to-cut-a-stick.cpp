class Solution {
public:
    int f(int i , int j , vector<int>& cuts ,vector<vector<int>> &dp){
        if(i>j) return 0;
        int cost = 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k = i ; k<=j ; k++){
            int ans = cuts[j+1]-cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
            cost = min(ans,cost);
        }
        return dp[i][j]=cost;

    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+2,vector<int>(c+2,-1));
        return f(1,c,cuts,dp);
        
        
    }
};