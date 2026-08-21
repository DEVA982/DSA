class Solution {
public:
    void solve (vector<int> &visited,string&s , vector<string>&ans,int n,int ind){
        if (ind == n+1){
            ans.push_back(s);
            return;
        }
        for(int a=1;a<=n;a++){
            if(visited[a]==0){
                visited[a]=1;
                
                s.push_back('0'+a);
                solve(visited,s,ans,n,ind+1);
                visited[a]=0;
                s.pop_back();
            }
        }
    }
    string getPermutation(int n, int k) {
        string s;
        vector<int>visited(n+1,0);
        vector<string>ans;
        solve(visited,s,ans,n,1);
        return ans[k-1];

        
    }
};