class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for(int i=0;i<n;i+=2)
            res += nums[i];
        return res;
    }
};