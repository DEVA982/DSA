class Solution {
public:
    int f(vector<int>& prices , int ind ,int buy , const int n , vector<vector<int>> &dp){
        if(ind == n){
            return 0;
            
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        if(buy){
            int take = -prices[ind]+f(prices,ind+1,0,n,dp);
            int not_take = f(prices,ind+1,1,n,dp);
            return dp[ind][buy]=max(take,not_take);
        }
        
        
        if(buy==0){
            int not_sell = f(prices,ind+1,0,n,dp);
            int sell = prices[ind]+f(prices,ind+1,1,n,dp);
            
            return dp[ind][buy]=max(sell,not_sell);
        }
        return dp[ind][buy];
        

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int ind = n-1 ; ind>=0 ; ind--){
            for (int buy = 0 ; buy<=1 ; buy++){
                if(buy){
                    int take = -prices[ind]+f(prices,ind+1,0,n,dp);
                    int not_take = f(prices,ind+1,1,n,dp);
                    dp[ind][buy]=max(take,not_take);
                }
                else{
                    int not_sell = f(prices,ind+1,0,n,dp);
                    int sell = prices[ind]+f(prices,ind+1,1,n,dp);
                    
                    dp[ind][buy]=max(sell,not_sell);
                }
            }
        }
        return dp[0][1];
    }
};