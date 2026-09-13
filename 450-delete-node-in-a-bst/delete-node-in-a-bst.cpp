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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val==key) return helper(root);
        TreeNode* dumy = root;
        while(root!=nullptr){
            if(root->left!=nullptr && root->left->val==key){
                root->left=helper(root->left);
                break;
            }
            else if(root->right!=nullptr && root->right->val==key){
                root->right=helper(root->right);
                break;
            }
            else if(key<root->val){
                root=root->left;
            }
            else{
                root=root->right;
            }

        }
        return dumy;
        
    }
    TreeNode* helper(TreeNode* root){
        if (root->left == nullptr) return root->right;
        else if(root->right == nullptr) return root->left;
        TreeNode* extremeright=extremeRight(root->left);
        extremeright->right=root->right;
        return root->left;
        
    }
    TreeNode* extremeRight(TreeNode* root){
        if(root->right==nullptr) return root;
        return extremeRight(root->right);
    }
};