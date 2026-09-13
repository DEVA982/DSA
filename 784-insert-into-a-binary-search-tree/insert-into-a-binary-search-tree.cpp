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
    TreeNode* insertIntoBST(TreeNode* root, int target) {
        if(root==nullptr){
            return new TreeNode( target);
        }
        if(target<root->val){
            root->left=insertIntoBST(root->left,target);
        }
        else{
            root->right=insertIntoBST(root->right,target);
        }
        return root;
        
    }
};