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
    int amountOfTime(TreeNode* root, int start) {
        map<int,vector<int>> adj;
        helper(root,adj);

        int ans = -1;
        queue<int> q;
        map<int,bool> vis;
        q.push(start);
        vis[start] = 1;

        while(! q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                int curr = q.front();
                q.pop();

                for(auto k: adj[curr])
                {
                    if(vis[k]) continue;
                    vis[k] = 1;
                    q.push(k);
                }
            }
            ans++;
        }

        return ans;
    }
};