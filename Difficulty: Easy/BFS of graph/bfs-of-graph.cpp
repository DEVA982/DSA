class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int> ans;
        vector<int> flag(n,0);
        queue<int> q;
        q.push(0);
        flag[0]=1;
        
        while(!q.empty()){
            int curr_element = q.front();
            q.pop();
            int a = adj[curr_element].size();
            for(int num :adj[curr_element] ){
                if(flag[num]==0){
                    q.push(num);
                    flag[num]=1;
                }
            }
            ans.push_back(curr_element);
            
        }
        return ans;
        
    }
};