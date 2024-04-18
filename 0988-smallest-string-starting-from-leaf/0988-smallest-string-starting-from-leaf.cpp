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
    priority_queue<string, vector<string>, greater<string>> pq;

    void solve(TreeNode * root, string curr)
    {
        char ch = ('a' + root->val);
        curr += ch;
        if(!root->left && !root->right)
        {
            reverse(curr.begin(),curr.end());
            pq.push(curr);
            return;
        }
        if(root->left) solve(root->left,curr);
        if(root->right) solve(root->right,curr);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string curr;
        solve(root,curr);
        return pq.top();
    }
};