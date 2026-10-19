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
    unordered_map<int,TreeNode*> mp;
    void func(vector<TreeNode*>& trees){
        for(auto &root: trees){
            mp[root->val]=root;
        }
        
    }
    bool merge(TreeNode* root,long long low,long long high){
        if(!root) return true;
        if(root->val<=low || root->val>=high) return false;
        if(!root->left && !root->right && mp.count(root->val)){
            TreeNode* node =mp[root->val];
            root->left=node->left;
            root->right=node->right;
            mp.erase(root->val);
        }
        return merge(root->left,low,root->val) && merge(root->right,root->val,high);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int n=trees.size();
        func(trees);
        unordered_set<int> leaves;
        for(auto root:trees){
            if(root->left) leaves.insert(root->left->val);
            if(root->right) leaves.insert(root->right->val);
        }

        TreeNode* ans=nullptr;
        for(auto &root:trees){
            if(!leaves.count(root->val)){
                if(ans!=nullptr) return nullptr;
                ans=root;
            }
        }
        if (!ans) return nullptr;

        mp.erase(ans->val);

        if (!merge(ans, LLONG_MIN, LLONG_MAX))
            return nullptr;

        if (!mp.empty())
            return nullptr;

        return ans;

    }
};