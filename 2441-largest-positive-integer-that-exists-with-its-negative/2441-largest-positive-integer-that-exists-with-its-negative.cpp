class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int a = abs(nums[i]), b = abs(nums[j]);
            int c = nums[i], d = nums[j];
            if (a == b && c * -1 == d || d * -1 == c)
                return a;
            if (a > b)
                i++;
            else
                j--;
        }
        return -1;
    }
};