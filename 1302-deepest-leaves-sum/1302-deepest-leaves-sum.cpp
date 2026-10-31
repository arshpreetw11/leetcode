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
    int mx=0,sum=0;

    void dfs(TreeNode* root,int depth){
        if(!root) return ;
        if(mx<depth){
            mx=depth;
            sum=root->val;
        }else if(mx==depth){
            sum+=root->val;
        }
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};