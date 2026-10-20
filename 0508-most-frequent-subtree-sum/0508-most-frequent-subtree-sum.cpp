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
    int generate(TreeNode* root){
        if(!root) return 0;
        int left=generate(root->left);
        int right=generate(root->right);
        int sum=root->val+left+right;
        freq[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        int mx=0;
        generate(root);

        for(auto &[n,f]:freq){
            mx=max(mx,f);
        }
        for(auto &[n,f]:freq){
            if(mx==f){
                res.push_back(n);
            }
        }
        return res;
    }
};