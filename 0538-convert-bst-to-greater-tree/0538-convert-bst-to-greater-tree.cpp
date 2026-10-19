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
    void GreaterTree(TreeNode* root,int &prevSum){
        if(!root) return ;
        GreaterTree(root->right,prevSum);
        prevSum+=root->val;
        root->val=prevSum;
        GreaterTree(root->left,prevSum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int prev=0;
        GreaterTree(root,prev);
        return root;
    }
};