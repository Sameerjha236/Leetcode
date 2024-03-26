class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0)
                nums[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int k = abs(nums[i]);
            if (k > n || k == 0) {
                nums[i] = 0;
                continue;
            }
            if (nums[k - 1] == 0)
                nums[k - 1] = k;
            else if (nums[k - 1] < 0) {
                if (nums[i] > 0)
                    nums[i] = 0;
                continue;
            } else
                nums[k - 1] *= -1;

            if (nums[i] > 0)
                nums[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                return i + 1;
        }
        return n + 1;
    }
};