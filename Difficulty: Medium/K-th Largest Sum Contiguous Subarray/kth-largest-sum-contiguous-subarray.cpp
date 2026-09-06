class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(int i = 0 ; i<arr.size() ; i++){
            int sum = 0;
            for(int j = i ; j<arr.size() ; j++){
                sum=sum+arr[j];
                if(minheap.size()<k){
                    minheap.push(sum);
                }
                else{
                    if(sum>minheap.top()){
                        minheap.pop();
                        minheap.push(sum);
                    }
                }
            }
        }
        return minheap.top();
        
    }
};