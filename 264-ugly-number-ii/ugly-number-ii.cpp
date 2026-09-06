class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);

        ugly[0] = 1;

        int i2 = 0;
        int i3 = 0;
        int i5 = 0;

        for (int i = 1; i < n; i++) {

            int a = ugly[i2] * 2;
            int b = ugly[i3] * 3;
            int c = ugly[i5] * 5;

            ugly[i] = min({a, b, c});

            if (ugly[i] == a)
                i2++;

            if (ugly[i] == b)
                i3++;

            if (ugly[i] == c)
                i5++;
        }

        return ugly[n - 1];
    }
};