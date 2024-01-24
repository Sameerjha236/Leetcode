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

    int dfs(TreeNode * root, int even, int odd, unordered_map<int,int> store)
    {
        if(!root)
            return 0;
        int curr = root->val;
        int f = store[curr];
        if(f == 0)
        {
            odd++;
            store[curr] = 1;
        }
        else if(f%2)
        {
            odd--;
            even++;
        }
        else
        {
            odd++;
            even--;
        }
        store[curr] = f + 1;

        int a = 0, b = 0;
        if(!root->left && !root->right)
        {
            if(odd==1 || odd == 0) return 1;
            return 0;
        }
        if(root->left)
            a = dfs(root->left,even,odd,store);
        if(root->right)
            b = dfs(root->right,even,odd,store);
        return a+b;
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> store;
        int even = 0, odd = 0;
        int ans = dfs(root,even,odd,store);
        return ans;
    }
};