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
    unordered_map<int,int> freq;
    void traverse(TreeNode* root){
        if(!root) return ;
        freq[root->val]++;
        traverse(root->left);
        traverse(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        traverse(root);
        int mx=0;
        for(auto &[_,f]:freq){
            mx=max(f,mx);
        }
        vector<int> ans;
        for(auto &[n,f]:freq){
            if(f==mx){
                ans.push_back(n);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};