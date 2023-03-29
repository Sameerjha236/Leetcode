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
vector<vector<int>> ans;
public:
    void f(TreeNode* root, int targetSum,vector<int>&sum,int s)
    {
        if(root==NULL)
        return;
        sum.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val+s==targetSum)
        {
            ans.push_back(sum);
        }
        f(root->left,targetSum,sum,s+root->val);
        f(root->right,targetSum,sum,s+root->val);
        sum.pop_back();

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        return ans;
        vector<int>sum;
        f(root,targetSum,sum,0);
        return ans;
        
        
    }
};