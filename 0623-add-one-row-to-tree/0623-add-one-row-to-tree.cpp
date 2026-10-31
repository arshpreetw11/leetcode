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
    TreeNode* node;
    void dfs(int val,int depth,int d,TreeNode* root){
        if(!root) return;
        if(d==depth-1){
            TreeNode* n1=new TreeNode(val);
            TreeNode* n2=new TreeNode(val);
            TreeNode* left=root->left;
            TreeNode* right=root->right;
            root->left=n1;
            root->right=n2;
            n1->left=left;
            n2->right=right;
            node=root;
            return;
        }
        dfs(val,depth,d+1,root->left);
        dfs(val,depth,d+1,root->right);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        node=root;
        if(depth==1){
            TreeNode* n=new TreeNode(val);
            n->left=root;
            return n;
        }
        dfs(val,depth,1,root);
        return root;
    }
};