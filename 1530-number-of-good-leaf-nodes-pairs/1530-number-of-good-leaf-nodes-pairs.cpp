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
    int ans=0;
    vector<int> count(TreeNode* root,int distance){
        if(!root) return {};
        if(!root->left && !root->right){
            return {1};
        }
        vector<int> left=count(root->left,distance);
        vector<int> right=count(root->right,distance);

        for(int x:left){
            for(int y:right){
                if(x+y<=distance){
                    ans++;
                }
            }
        }
        vector<int> res;
        for(int x:left){
            if(x+1<=distance){
                res.push_back(x+1);
            }
        }
        for(int x:right){
            if(x+1<=distance){
                res.push_back(x+1);
            }
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        count(root,distance);
        return ans;
    }
};