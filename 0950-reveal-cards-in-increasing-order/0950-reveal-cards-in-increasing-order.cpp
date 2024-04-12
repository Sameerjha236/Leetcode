class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        int n = deck.size();
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; i++)
            q.push(i);
        
        for (int i = 0; i < n; i++) {
            int curr = q.front();
            q.pop();
            ans[curr] = deck[i];
            if (!q.empty()) {
                int k = q.front();
                q.pop();
                q.push(k);
            }
        }

        return ans;
    }
};