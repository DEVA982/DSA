class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int n = s.size();
        int ans = 0;
        int maxFreq = 0;
        unordered_map<char, int> charset;

        for (int right = 0; right < n; right++) {
            charset[s[right]]++;
            maxFreq=max(maxFreq,charset[s[right]]);
            while(right-left+1-maxFreq > k){
                charset[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }

        return ans;
    }
};