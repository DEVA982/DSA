class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0 ; i<arr.size();i++){
            pq.push({arr[i],i});
        }
        int rank = 0;
        for(int i = 0 ; i<arr.size();i++){
            auto[value,index]=pq.top();
            pq.pop();
            arr[index]=rank;
            rank++;
        }
    }
};