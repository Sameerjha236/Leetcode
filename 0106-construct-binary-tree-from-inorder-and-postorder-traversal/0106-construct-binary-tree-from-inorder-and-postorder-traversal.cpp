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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> hm;
        for(int i=0;i<inorder.size();i++) hm[inorder[i]] = i;

        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hm);
    }

    TreeNode * helper(vector<int> & inorder, int is, int ie, vector<int> & postorder,int ps, int pe,unordered_map <int,int> &hm)
    {
        if(is>ie || ps>pe) return nullptr;

        TreeNode * root = new TreeNode(postorder[pe]);
        int ind = hm[postorder[pe]];
        int left = ind-is;

        root->left = helper(inorder,is,ind-1,postorder,ps,ps+left-1,hm);
        root->right = helper(inorder,ind+1,ie,postorder,ps+left,pe-1,hm);
        return root;
    }
};