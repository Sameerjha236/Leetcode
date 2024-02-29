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
public:
    bool isEvenOddTree(TreeNode* root) {
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size(), prev;
            if (level % 2 == 0) {
                prev = 1e9;
            } else {
                prev = -1;
            }

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                int k = curr->val;
                if (level % 2 == 1 && k % 2 == 1) {
                    if (prev >= k)
                        return 0;
                    prev = k;

                } else if (level % 2 == 0 && k % 2 == 0) {
                    if (prev <= k)
                        return 0;
                    prev = k;
                } else
                    return 0;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            level++;
        }
        return true;
    }
};