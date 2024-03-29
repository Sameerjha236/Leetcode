class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            long long int a = nums[i] * nums[i], b = nums[j] * nums[j];
            if (a >= b) {
                res.push_back(a);
                i++;
            } else {
                res.push_back(b);
                j--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};