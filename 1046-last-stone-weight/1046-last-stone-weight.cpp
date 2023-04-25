class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        int n = stones.size();
        if(n == 1)
            return stones[0];
            
        for(int i=0; i<n; i++) {
            pq.push(stones[i]);
        }

        while ( !pq.empty() ) {
            int x=0, y=0;
            if(!pq.empty()) {
                x = pq.top();
                pq.pop();
            }
            if(!pq.empty()) {
                y = pq.top();
                pq.pop();
            }
            if(x != y) {
                pq.push(x-y);
            }
            if(pq.size() == 1) {
                return pq.top();
            }
        }
        return 0;
    }
};