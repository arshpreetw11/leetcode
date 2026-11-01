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
    TreeNode* make(int low,int high,vector<int> &nums){
        if(low>high) return nullptr;
        int mx=low;
        for(int i=low+1;i<high+1;i++){
            if(nums[i]>nums[mx]){
                mx=i;
            }
        }
        TreeNode *r=new TreeNode(nums[mx]);
        r->left=make(low,mx-1,nums);
        r->right=make(mx+1,high,nums);
        return r;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return make(0,nums.size()-1,nums);
    }
};