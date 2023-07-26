/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node * temp=head;
        unordered_map<Node *,Node *> hash;
        vector<Node *> store;
        temp = head;
        while(temp)
        {
            Node * curr = new Node(temp->val);
            hash[temp] = curr;
            store.push_back(curr);
            temp = temp->next;
        }
        temp = head;
        for(int i=0;temp;i++)
        {
            Node * ran = temp->random;
            Node * forw = temp->next;
            if(ran) store[i]->random = hash[ran];
            if(forw) store[i]->next = hash[forw];
            temp = temp->next;
        }
        return store[0];

    }
};