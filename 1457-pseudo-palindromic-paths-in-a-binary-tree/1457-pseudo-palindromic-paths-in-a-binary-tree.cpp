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
    int ans = 0;
    bool pal_checker(vector<int>&fr){
        int ind = 0;
        for(int i : fr){
            if(i%2 == 1){
                ind++;
            }
        }
        
        return ind <= 1;
    }
    void solve(TreeNode* root,vector<int>&fr){
       if(root -> left == NULL && root -> right == NULL){
           if(pal_checker(fr)){
               ans++;
           }
           return ;
       } 
        
       if(root->left != NULL){
           fr[root->left->val]++;
           solve(root->left,fr);
           fr[root->left->val]--;
       }  
       if(root->right != NULL){
           fr[root->right->val]++;
           solve(root->right,fr);
           fr[root->right->val]--;
       }  
        
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>fr(10,0);
        fr[root->val]++;
        solve(root,fr);
        return ans;
    }
};