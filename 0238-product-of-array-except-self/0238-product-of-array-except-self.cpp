class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int cnt = 0, total = 1, ez = 1;
        for (auto k : nums) {
            if (k == 0) {
                cnt++;
                if (cnt > 1) {
                    vector<int> ans(nums.size(), 0);
                    return ans;
                }
                total = 0;
            } else {
                total *= k;
                ez *= k;
            }
            // cout<<total<<" "<<ez<<endl;
        }
        vector<int> ans;
        for (auto k : nums) {
            if (k == 0)
                ans.push_back(ez);
            else
                ans.push_back(total / k);
        }
        return ans;
    }
};