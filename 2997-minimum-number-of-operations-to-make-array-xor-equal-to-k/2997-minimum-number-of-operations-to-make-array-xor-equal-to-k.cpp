class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int x = 0;
        for (int i = 0; i < nums.size(); i++) {
            x ^= nums[i];
        }
        int res = x ^ k;
        int cnt = 0;
        while (res) {
            cnt += (res & 1);
            res >>= 1;
        }
        return cnt;
    }
};