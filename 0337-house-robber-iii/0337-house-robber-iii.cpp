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
    unordered_map<TreeNode * , int> dp;
public:
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        if(dp.find(root) != dp.end()) return dp[root];
        int tk = 0, nt = 0;
        nt = rob(root->left) + rob(root->right);

        int a = 0, b = 0, c = 0, d = 0;
        if (root->left) {
            a = rob(root->left->left);
            b = rob(root->left->right);
        }
        if (root->right) {
            c = rob(root->right->right);
            d = rob(root->right->left);
        }
        tk = a + b + c + d + root->val;
        return dp[root] =  max(tk, nt);
    }
};