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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool b=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++)
            {
                TreeNode * node =q.front();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                q.pop();
                if(b==0)
                {
                    level.push_back(node->val);
                }
                else
                {
                    level.insert(level.begin(),node->val);
                }
            }
            ans.push_back(level);
            if(b==0) b=1;
            else b=0;
        }
        return ans;
    }
};