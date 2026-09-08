class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2,vector<int>& temp){
        int i = 0;
        int j = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            temp.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            temp.push_back(nums2[j]);
            j++;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        merge(nums1,nums2,temp);
        int n = temp.size();
        double ans=0;
        if(n%2==0){
            int p = n/2;
            //cout<<temp[p-1]<<" "<<temp[p];
            ans=double (temp[p-1]+temp[p])/2;
        }
        else{
            int p = n/2;
            ans=temp[p];
        }
        return ans;
        

    }
};