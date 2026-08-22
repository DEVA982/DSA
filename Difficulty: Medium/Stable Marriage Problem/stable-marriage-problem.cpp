class Solution {
public:

    vector<int> stableMarriage(vector<vector<int>> &men,
                               vector<vector<int>> &women) {

        int n = men.size();

        // menList[m] = woman currently matched with man m
        vector<int> menList(n, -1);

        // womenList[w] = man currently matched with woman w
        vector<int> womenList(n, -1);

        // next[m] = next woman to whom man m should propose
        vector<int> next(n, 0);

        // rank[w][m] = preference rank of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));

        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }

        // Find a free man
        while (true) {

            int menind = -1;

            for (int m = 0; m < n; m++) {
                if (menList[m] == -1) {
                    menind = m;
                    break;
                }
            }

            // No free man -> everyone is matched
            if (menind == -1)
                break;

            // Man proposes to his next choice
            int w = men[menind][next[menind]];
            next[menind]++;

            // Woman is free
            if (womenList[w] == -1) {

                menList[menind] = w;
                womenList[w] = menind;
            }

            // Woman already has a partner
            else {

                int currentMan = womenList[w];

                // Woman prefers new man
                if (rank[w][menind] < rank[w][currentMan]) {

                    // Current man gets rejected
                    menList[currentMan] = -1;

                    // New man gets accepted
                    womenList[w] = menind;
                    menList[menind] = w;
                }

                // Otherwise new man is rejected
                // He remains free and will propose
                // to his next choice in the next iteration.
            }
        }

        return menList;
    }
};