class Solution {
public:
    bool isKSortedArray(vector<int>& arr, int k) {

        int n = arr.size();

        // Sorted array gives target positions
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // First k+1 elements
        for (int i = 0; i <= k && i < n; i++) {
            pq.push({arr[i], i});
        }

        for (int i = 0; i < n; i++) {

            auto [value, original] = pq.top();
            pq.pop();

            // value should be the element at sorted position i
            if (value != sorted[i]) {
                return false;
            }

            // Its target position is i
            if (abs(original - i) > k) {
                return false;
            }

            // Add next element
            if (i + k + 1 < n) {
                pq.push({arr[i + k + 1], i + k + 1});
            }
        }

        return true;
    }
};