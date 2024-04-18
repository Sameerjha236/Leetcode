/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    void solve(TreeNode* root, int curr, int val, int depth) {
        if (!root)
            return;
        if (curr == depth) {
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            l->left = root->left;
            r->right = root->right;
            root->left = l;
            root->right = r;
            return;
        }
        solve(root->left, curr + 1, val, depth);
        solve(root->right, curr + 1, val, depth);
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
        {
            TreeNode* l = new TreeNode(val);
            l->left = root;
            return l;
        }
        solve(root, 1, val, depth - 1);
        return root;
    }
};