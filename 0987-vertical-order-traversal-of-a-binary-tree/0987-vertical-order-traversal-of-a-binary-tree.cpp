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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> store;
        map<int,vector<int>> hash;

        store.push(make_pair(root,0));
        while(!store.empty())
        {
            int n = store.size();
            map<int,vector<int>> temp;
            while(n--)
            {
                auto node = store.front();
                store.pop();
                if(node.first->left) 
                    store.push(make_pair(node.first->left,node.second-1));
                if(node.first->right) 
                    store.push(make_pair(node.first->right,node.second+1));
                
                temp[node.second].push_back(node.first->val);
                // hash[node.second].push_back(node.first->val);
            }
            for(auto i:temp)
            {
                sort(i.second.begin(),i.second.end());
                for(auto j:i.second)
                {
                    hash[i.first].push_back(j);
                }
            }
        }

        for(auto i:hash)
            ans.push_back(i.second);
        return ans;
    }
};