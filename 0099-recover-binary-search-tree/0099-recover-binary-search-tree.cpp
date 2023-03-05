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
private: 
TreeNode * first, *prev, * middle, *last;

void inorder(TreeNode * root)
{
    if(root==nullptr) return;
    inorder(root->left);
    
    if(prev!=nullptr && (root->val< prev->val))
    {
        if(first==nullptr)
        {
            first = prev;
            middle = root;
        }
        else last = root;
    }
    prev = root;
    inorder(root->right);
}

public:
    void recoverTree(TreeNode* root) {
        first = prev = middle = last = nullptr;
        inorder(root);
        if(last==nullptr)
            swap(first->val,middle->val);
        else
            swap(first->val,last->val);
    }
};