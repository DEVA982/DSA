class Solution {
public:
    void inorder(Node* root, vector<int>& arr) {
        if (root == nullptr)
            return;

        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    vector<int> merge(Node* r1, Node* r2) {
        vector<int> a, b, ans;

        // Inorder traversal of both BSTs
        inorder(r1, a);
        inorder(r2, b);

        // Merge the two sorted arrays
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }

        // Remaining elements of first array
        while (i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }

        // Remaining elements of second array
        while (j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }
};