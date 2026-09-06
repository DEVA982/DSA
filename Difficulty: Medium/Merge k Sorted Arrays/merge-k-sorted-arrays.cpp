class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minheap;
        for (int i = 0 ; i<mat.size();i++){
            minheap.push({mat[i][0],{i,0}});
        }
        vector<int> ans;
        while(minheap.size()>0){
            int value=minheap.top().first;
            int row = minheap.top().second.first;
            int col = minheap.top().second.second;
            minheap.pop();
            ans.push_back(value);
            if(col+1<mat[0].size()){
                minheap.push({mat[row][col+1],{row,col+1}});
                
            }
        }
        return ans;
    }
};