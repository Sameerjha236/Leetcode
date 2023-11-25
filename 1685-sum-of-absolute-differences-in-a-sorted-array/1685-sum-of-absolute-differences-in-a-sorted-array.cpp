class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> pre(n), suff(n);

        pre[0] = nums[0];
        suff[n - 1] = nums[n - 1];
        

        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + nums[i];
            suff[n - i - 1] = suff[n - i] + nums[n - i - 1];
        }
        

        for (int i = 0; i < n; ++i) {
            int curr = ((nums[i] * i) - pre[i]) + (suff[i] - (nums[i] * (n - i - 1)));
            result[i] = curr;
        }
        
        return result;
    }
};