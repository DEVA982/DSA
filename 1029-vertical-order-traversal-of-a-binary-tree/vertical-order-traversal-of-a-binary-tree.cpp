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
    void dfs(TreeNode* node,int row,int col,vector<tuple<int,int,int>> &nodes){
        if(node==nullptr) return;
        nodes.emplace_back(col,row,node->val);
        dfs(node->left,row+1,col-1,nodes);
        dfs(node->right,row+1,col+1,nodes);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;
        vector<vector<int>> ans;
        dfs(root,0,0,nodes);
        sort(nodes.begin(),nodes.end());
        int prev_col=INT_MIN;
        for(auto[col,row,val]:nodes){
            if(prev_col!=col){
                ans.push_back({});
                prev_col=col;

            }
            ans.back().push_back(val);
        }
        return ans;
        
    }
};