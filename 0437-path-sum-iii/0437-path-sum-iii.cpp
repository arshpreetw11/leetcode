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
int cnt=0;
    void dfs(TreeNode* node,int targetSum,long long sum){
        if(node==NULL) return;
        sum+=node->val;
        
        if(sum==targetSum){
            cnt++;
        }
        
        dfs(node->left,targetSum,sum);
        dfs(node->right,targetSum,sum);
    }
    void traverse(TreeNode* node,int targetSum){
        if(!node) return;
        dfs(node,targetSum,0);
        traverse(node->left,targetSum);
        traverse(node->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        traverse(root,targetSum);
        return cnt;
    }
};