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

    TreeNode * merge(int l, int h, vector<int> &nums)
    {
        if(l>h) return nullptr;
        int m = (l+h)/2;
        TreeNode * curr = new TreeNode (nums[m]);
        curr->left = merge(l,m-1,nums);
        curr->right = merge(m+1,h,nums);
        return curr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * head=nullptr;
        head = merge(0,nums.size()-1,nums);
        return head;
    }
};