/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
        {
            return NULL;
        }
        map<Node *, Node*> mp;
        Node * root = new Node(node -> val);
        mp[node] = root;
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            // cout<< it -> val << endl;
            for(auto nd: it -> neighbors)
            {
                if(mp[nd] == NULL)
                {
                    // cout<< nd -> val << endl;
                    Node * nnd = new Node(nd -> val);
                    mp[nd] = nnd;
                    q.push(nd);
                }
                // cout <<"size" <<  mp[it] -> neighbors . size()<< endl;
                mp[it] -> neighbors.push_back(mp[nd]);
                
            }
        }
        return root;
    }
};