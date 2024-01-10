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
    void helper(TreeNode * root, map<int,vector<int>> &adj)
    {
        if(!root) return;
        int a = root->val;
        if(root->left)
        {
            int b = root->left->val;
            adj[a].push_back(b);
            adj[b].push_back(a);
            helper(root->left,adj);
        }
        
        if(root->right)
        {
            int b = root->right->val;
            adj[a].push_back(b);
            adj[b].push_back(a);
            helper(root->right,adj);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0)
        {
            return {target->val};
        }
        map<int,vector<int>> adj;
        helper(root,adj);
        map<int,int> dis;

        int d = 0;
        queue<int> q;
        q.push(target->val);
        vector<int> ans;

        while(!q.empty())
        {
            int n = q.size();
            d++;
            for(int i=0;i<n;i++)
            {
                int curr = q.front();
                q.pop();
                for(auto x:adj[curr])
                {
                    if(x == target->val || dis[x] != 0) continue;
                    dis[x] = d;
                    q.push(x);
                    if(d == k) ans.push_back(x);
                }
            }
        }

        return ans;
    }
};