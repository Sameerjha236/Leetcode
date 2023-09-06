class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        vector <ListNode*> ret;
        ListNode* temp=head;
        while(temp) {
            temp=temp->next;
            len++;
        }
        int size=len/k;
        int rem=len%k;
        temp=head;
        while(temp!=NULL) {
            ListNode* c=new ListNode(100);
            ListNode* tempC=c;
            int s=size;
            if(rem>0) 
                s++;
                rem--;
            
            for(int i=1;i<=s;i++) {
                tempC->next=temp;
                temp=temp->next;
                tempC=tempC->next;
            }
            tempC->next=NULL;
            ret.push_back(c->next);
        }
        if(ret.size()<k) {
            int extra=k-ret.size();
            for(int i=1;i<=extra;i++)ret.push_back(NULL);
        }
        return ret;
    }
};