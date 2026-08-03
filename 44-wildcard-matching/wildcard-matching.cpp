class Solution {
public:
    int f(string &s, string &p , int i , int j,vector<vector<int>>&dp){

        if(i<0){
            if(j<0) return 1;
            while(j>=0){
                if(p[j]!='*'){
                    return 0;
                }
                j--;
            }
            return 1;

        }
        if(j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j]){
            return dp[i][j]=f(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='?'){
            return dp[i][j]=f(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j]=f(s, p, i, j - 1,dp) || f(s, p, i - 1, j,dp);
        }
        return 0;

    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(s,p,n-1,m-1,dp);

        
    }
};