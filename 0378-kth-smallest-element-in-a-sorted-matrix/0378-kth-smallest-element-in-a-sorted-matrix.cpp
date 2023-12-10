class Solution {
public:
    int kthSmallest(vector<vector<int>>& vec, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i:vec) for(auto j: i) pq.push(j);
        while(k>=0)
        {
            k--;
            if(k == 0) return pq.top();
            pq.pop();
        }
        return 0;
    }
};