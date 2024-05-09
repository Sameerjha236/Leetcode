class Solution {
public:
    long long maximumHappinessSum(vector<int>& vec, int k) {
        sort(vec.rbegin(), vec.rend());
        long long ans = 0;
        int i = 0;
        while (k--) {
            if(vec[i] - i <= 0) break;
            ans += (vec[i] - i);
            i++;
        }
        return ans;
    }
};