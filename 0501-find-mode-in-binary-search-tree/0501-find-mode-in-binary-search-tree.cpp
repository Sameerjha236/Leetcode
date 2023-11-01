class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> hash;
        int m = 0;
        inorder(root,hash,m);
        vector<int> result;
        for(auto k:hash)
        {
            if(k.second == m) result.push_back(k.first);
        }
        return result;
    }

private:
    void inorder(TreeNode* root, unordered_map<int,int> &hash, int &m) 
    {
        if (!root) return;
        hash[root->val]++;
        m = max(hash[root->val],m);
        inorder(root->left, hash,m);
        inorder(root->right, hash,m);
    }
};