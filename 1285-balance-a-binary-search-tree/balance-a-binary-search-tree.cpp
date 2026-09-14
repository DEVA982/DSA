#include<bits/stdc++.h>
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
    void inorder(TreeNode* root,vector<int> & ans){
        if(root==nullptr){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* insertTree(vector<int> ans,int low ,int high){
        if (low > high)
            return nullptr;
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left=insertTree(ans,low,mid-1);
        root->right=insertTree(ans,mid+1,high);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return insertTree(ans,0,ans.size()-1);
        
    }
};