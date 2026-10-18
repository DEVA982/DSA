class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> charset;

        while(right < n) {
            if(charset[s[right]] == 0) {
                charset[s[right]] = 1;
                ans = max(ans, right - left + 1);
                right++;
            }
            else {
                charset[s[left]] = 0;
                left++;
            }
        }

        return ans;
    }
};