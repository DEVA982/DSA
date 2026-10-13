
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsee(n), psee(n);
        stack<int> st;

        // Next smaller or equal element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nsee[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous strictly smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long ans = 0;
        const long long mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nsee[i] - i;

            ans = (ans + (1LL * arr[i] * left % mod) * right % mod) % mod;
        }

        return ans;
    }
};
