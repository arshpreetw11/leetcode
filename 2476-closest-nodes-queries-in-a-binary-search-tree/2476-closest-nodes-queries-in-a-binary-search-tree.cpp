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
    vector<int> nodes;
    void traverse(TreeNode* root){
        if(!root) return;
        nodes.push_back(root->val);
        traverse(root->left);
        traverse(root->right);      
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        traverse(root);
        sort(nodes.begin(),nodes.end());
        vector<vector<int>> ans;
        for(int q:queries){
            int mn=-1,mx=-1;
            auto it = lower_bound(nodes.begin(), nodes.end(), q);
            if (it != nodes.end() && *it == q)
                mn = q;
            else if (it != nodes.begin())
                mn = *(it - 1);
            if (it != nodes.end())
                mx = *it;
            ans.push_back({mn,mx});
        }
        return ans;
    }
};