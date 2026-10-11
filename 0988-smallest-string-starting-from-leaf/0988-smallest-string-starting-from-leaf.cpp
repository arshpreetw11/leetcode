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
vector<string> store;
    void dfs(TreeNode* node,string res){
        if(!node) return ;
        if(!node->left && !node->right){
            res+=string(1, node->val + 'a');
            store.push_back(res);
            return ;
        }
        dfs(node->left,res+string(1, node->val + 'a'));
        dfs(node->right,res+string(1, node->val + 'a'));
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        string res="";
        for(string s:store){
            reverse(s.begin(),s.end());
            if(res=="" || s<res){
                res=s;
            }
        }
        return res;
    }
};