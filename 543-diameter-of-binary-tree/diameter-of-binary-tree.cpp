/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameter=0;
    int depth(TreeNode* root){
        if(root==nullptr) return 0;
        int leftTree=depth(root->left);
        int rightTree=depth(root->right);
        diameter=max(diameter,leftTree+rightTree);
        return 1+max(leftTree,rightTree);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;

        
    }
};