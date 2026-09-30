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
    vector<TreeNode*> store;
    void tree(TreeNode* root){
        if(!root) return ;
        TreeNode* node=new TreeNode(root->val);
        store.push_back(node);
        tree(root->left);
        tree(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode* node=root;
        tree(node);

        sort(store.begin(),store.end(),[&](TreeNode* a,TreeNode* b){
            return a->val<b->val;
        });

        TreeNode* res=new TreeNode(store[0]->val);
        root=res;
        for(int i=1;i<store.size();i++){
            res->right=store[i];
            res=res->right;
        }
        return root;
    }
};