/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void backtrack(TreeNode * root,TreeNode* curr, bool &flag, vector<TreeNode *> & store)
    {
        if(root==nullptr)
            return;
        if(root->val == curr->val)
        {
            flag=1;
            store.push_back(root);
            return;
        }
        if(flag==1)
        {
            store.push_back(root);
            return;
        }
        backtrack(root->left,curr,flag,store);
        if(flag==1)
        {
            store.push_back(root);
            return;
        }
        backtrack(root->right,curr,flag,store);
        if(flag==1)
        {
            store.push_back(root);
            return;
        }
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> first;
        vector<TreeNode *> second;
        bool f=0;
        backtrack(root,p,f,first);
        f=0;
        backtrack(root,q,f,second);
        for(auto i:first)
        {
            for(auto j:second)
            {
                if(i==j)
                    return i;
            }
        }
        return root;
    }
};