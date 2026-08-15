class Solution {
public:
    int solve(int ind ,vector<vector<int>>& matrix ){
        int n = matrix[ind].size();
        vector<int> right(n,0);
        vector<int> left(n,0);
        stack<int>s;
        for(int i = n-1 ; i>=0 ; i--){
            while(s.size()>0 && matrix[ind][s.top()]>=matrix[ind][i]){
                s.pop();
            }
            right[i]=s.empty()?n:s.top();
            s.push(i);
    
        }
        while(!(s.empty())){
            s.pop();

        }
        for(int i = 0 ; i<n ; i++){
            while(s.size()>0 && matrix[ind][s.top()]>=matrix[ind][i]){
                s.pop();
            }
            left[i]=s.empty()?-1:s.top();
            s.push(i);
    
        }
        int ans =0;
        for(int i = 0 ; i< n ; i++){
            int cost = matrix[ind][i]*(right[i]-left[i]-1);
            ans = max(cost,ans);
        }
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        //int ans = solve(0,matrix) ;
        vector<vector<int>> height(n,vector<int>(matrix[0].size(),0));
        for(int j = 0 ; j<matrix[0].size();j++){
            if(matrix[0][j]=='1'){
                height[0][j]=1;
            }
        }
        int ans = solve(0,height) ;

        for(int i = 1 ; i<n ; i++){
            for(int j = 0 ; j<matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    height[i][j]=height[i-1][j] + 1;
                }
                else{
                    height[i][j]=0;
                }
                
            }
            int cost = solve(i,height);
            ans = max(ans,cost);
        }
        return ans;

        
    }
};