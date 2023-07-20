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

    void helper(vector<int> &ans,TreeNode * root)
    {
        if(!root) return;
        queue<TreeNode *> store;
        store.push(root);
        while(!store.empty())
        {
            int n = store.size();
            for(int i=0;i<n;i++)
            {
                TreeNode * curr = store.front();
                store.pop();
                if(curr->left) store.push(curr->left);
                if(curr->right) store.push(curr->right);
                if(i==n-1)
                    ans.push_back(curr->val);
            }
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        helper(ans,root);
        return ans;
    }
};