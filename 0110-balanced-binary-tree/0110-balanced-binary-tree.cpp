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
    int height(TreeNode *p){
	int x,y;
	if(p==NULL){
		return 0;
	}
	y=height(p->right);
	x=height(p->left);
	return x>y?x+1:y+1;
}
    bool isSame(TreeNode *r){
        if(r==NULL) return 1;
        if(r->left==NULL && r->right==NULL){
           return 1;
        }
        if(abs(height(r->left)-height(r->right))>1){ 
            cout<<r->val<<endl;
            return 0;}
        else return isSame(r->left) && isSame(r->right);

    }
    bool isBalanced(TreeNode* r) {
        if(r==NULL) return 1;
        return isSame(r);
    }
};