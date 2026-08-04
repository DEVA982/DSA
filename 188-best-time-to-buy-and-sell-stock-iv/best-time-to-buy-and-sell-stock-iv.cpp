class Solution {
public:
    int f(vector<int>& prices , int ind ,int buy , const int n ,int cap ,  vector<vector<vector<int>>> &dp){
        if(ind == n){
            return 0;
            
        }
        if(cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        
        if(buy){
            int take = -prices[ind]+f(prices,ind+1,0,n,cap,dp);
            int not_take = f(prices,ind+1,1,n,cap,dp);
            return dp[ind][buy][cap]=max(take,not_take);
        }
        
        
        if(buy==0){
            int not_sell = f(prices,ind+1,0,n,cap,dp);
            int sell = prices[ind]+f(prices,ind+1,1,n,cap-1,dp);
            
            return dp[ind][buy][cap]=max(sell,not_sell);
        }
        return dp[ind][buy][cap];
        

    }
    int maxProfit(int k,vector<int>& prices) {
        int cap = 2;
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(k+1, -1))
        );
        return f(prices,0,1,n,k,dp);
        
    }
};