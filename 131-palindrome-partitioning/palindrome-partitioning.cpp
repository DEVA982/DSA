class Solution {
public:
    bool isPalindrome(string s , int start , int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(int ind,string s,vector<vector<string>> &ans,vector<string>&ds){
        int n = s.size();
        if (ind==n){ 
            ans.push_back(ds);
            return;
        }
        for(int k = ind ; k<n ; k++){
            if(isPalindrome(s,ind,k)){
                ds.push_back(s.substr(ind, k - ind + 1));
                solve(k+1,s,ans,ds);
                ds.pop_back();
                
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>ds;
        solve(0,s,ans,ds);
        return ans;
        
    }
};