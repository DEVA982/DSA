class Solution {
public:
    int trap(vector<int>& height) {
        int count = 0 ;
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0] = height[0];
        right[n-1]=height[n-1];
        for (int i = 1 ; i<n ; i++){
            left[i]=max(left[i-1],height[i]);
        }
        for (int j = n-2 ; j>=0 ; j--){
            right[j]=max(right[j+1],height[j]);
        }
        
        for(int i = 0 ; i<n;i++){

            int water = min(left[i],right[i]);
            if(height[i]<water){
                count=count-height[i]+water;
            }
        }
        /*for(int i = 1 ; i<n-1 ;i++){
            //finding maximum in left subarray
            int left = height[0];
            for(int k = 0 ; k<i ;k++){
                if(height[k]>left){
                    left=height[k];
                }
            }
            int right = height[i+1];
            for(int l = i+1 ; l<n;l++){
                if(height[l]>right){
                    right=height[l];
                }
            }
            int water = min(left,right);
            if(height[i]<water){
                count=count-height[i]+water;
            }
        }*/
        return count;
        
    }
};