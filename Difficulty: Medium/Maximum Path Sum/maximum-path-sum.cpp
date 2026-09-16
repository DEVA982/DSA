/* Structure of binary tree node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    
    int solve(Node* root,int &ans){
        //int sum = 0;
        if(root==nullptr) return 0;
        int left = max(0,solve(root->left,ans));
        int right = max(0,solve(root->right,ans));
        int current = root->data+left+right;
        ans = max(ans,current);
        return root->data + max(left, right);
    }
    int findMaxSum(Node *root) {
        // code here
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
        
        
    }
};