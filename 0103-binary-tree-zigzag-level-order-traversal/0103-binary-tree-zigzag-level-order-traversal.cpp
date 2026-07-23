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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) return {};
        q.push(root);
        bool leftright=true;
        while(!q.empty()){
            int sz=q.size();
            vector<int> ans(sz);

            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                int idx=(leftright)?i:sz-1-i;
                ans[idx]=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            leftright=!leftright;
            res.push_back(ans);
        }
        return res;
    }
};