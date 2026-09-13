/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void solver(vector<int> &ans,Node*root){
        if(root==nullptr) return;
        solver(ans,root->left);
        ans.push_back(root->data);
        solver(ans,root->right);
    }
    int findMedian(Node* root) {
        // Code here
        vector<int>ans;
        
        solver(ans,root);
        
        int n = ans.size();
       
        if(n%2==0) return ans[(n/2)-1];
        return ans[(n)/2];
        
    }
};