class Solution {
public:
    int isPalindrome(int i ,int k , string &s){
        while(i<k){
            if(s[i]==s[k]){
                i++;
                k--;
            }
            else return 0;
        }
        return 1;
    }
    int f(int i, int n , string &s,vector<int> &dp){
        if(i==n) return -1 ;
        int min_cost = INT_MAX;
        if(dp[i]!=-1)return dp[i];
        for(int k= i ; k<n ; k++){
            if(isPalindrome(i,k,s)){
                int cost = 1+f(k+1,n,s,dp);
                min_cost=min(cost,min_cost);
            }

        }
        return dp[i]=min_cost;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return f(0,n,s,dp);
        
    }
};