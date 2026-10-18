class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int left = 0 ; 
        int right = 0 ;
        unordered_set <char> charset;
        while(right<n){
            if(charset.find(s[right])==charset.end()){
                charset.insert(s[right]);
                ans = max(ans,right-left+1);
                right++;
            }
            else{
                charset.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};