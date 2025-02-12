class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> hash;
        for (auto k : nums) {
            int curr = 0, tp = k;
            while (k) {
                curr += (k % 10);
                k = k / 10;
            }
            hash[curr].push(tp);
        }

        int ans = -1;

        for (auto curr : hash) {
            int a = curr.second.top();
            curr.second.pop();
            if (curr.second.empty())
                continue;
            int b = curr.second.top();
            ans = max(ans, a + b);
        }

        return ans;
    }
};