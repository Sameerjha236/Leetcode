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

    void inorder(TreeNode* root, vector<TreeNode*> &store)
    {
        if(!root) return;
        inorder(root->left,store);
        store.push_back(root);
        inorder(root->right,store);
    }

    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> store;
        inorder(root,store);

        int n = store.size();
        for(int i = n-2;i>=0;i--)
        {
            store[i]->val += store[i+1]->val; 
        }

        return root;
    }
};