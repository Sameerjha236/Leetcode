/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> store;
        store.push(root);

        while(!store.empty())
        {
            int n = store.size();
            for(int i=0;i<n;i++)
            {
                Node * curr = store.front();
                store.pop();
                if(i<n-1)
                    curr->next = store.front();
                if(curr->left) store.push(curr->left);
                if(curr->right) store.push(curr->right);
            }
        }
        return root;
    }
};