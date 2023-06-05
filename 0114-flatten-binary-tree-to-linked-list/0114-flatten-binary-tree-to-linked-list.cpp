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
    void preorder(TreeNode * root, vector<TreeNode *> &ds)
    {
        if(!root) return;
        ds.push_back(root);
        preorder(root->left,ds);
        preorder(root->right,ds);
    }

public:
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode *> ds;
        preorder(root,ds);
        for(int i=0;i<ds.size()-1;i++)
        {
            TreeNode * curr = ds[i];
            curr->left = nullptr;
            curr->right = ds[i+1];
        }

    }
};