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
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> store;
        int nl = 0;
        store.push(root);
        while (!store.empty())
        {
            int n = store.size();
            bool a = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = store.front();
                store.pop();
                if (!curr)
                {
                    nl--;
                    if (a == 0)
                    {
                        if (i == n - 1 && store.size() != nl)
                            return false;
                        a=1;
                    }
                    if(a==1 && store.size()!=nl) return false;
                }
                else
                {
                    if (a == 1)
                        return false;
                    if (!curr->left)
                        nl++;
                    if (!curr->right)
                        nl++;
                    store.push(curr->left);
                    store.push(curr->right);
                }
            }
        }
        return true;
    }
};