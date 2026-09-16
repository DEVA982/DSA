/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int height(Node* root){
        if(root==nullptr) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(Node* root) {
        // code here
        if(root==nullptr) {
            return true;
        }
        int left = height(root->left);
        int right = height(root->right);
        if(abs(left-right)>1) return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
};