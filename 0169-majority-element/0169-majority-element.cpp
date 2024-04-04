
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, curr = 0;
        for (auto k : nums) {
            if (curr == 0) {
                curr++;
                ans = k;
            } else if (ans == k) {
                curr++;
            } else {
                curr--;
            }
        }
        return ans;
    }
};