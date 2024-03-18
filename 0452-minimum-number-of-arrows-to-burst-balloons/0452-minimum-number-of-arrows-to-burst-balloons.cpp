class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& vec) {
        sort(vec.begin(), vec.end());
        long long int ans = 1, l = vec[0][0], r = vec[0][1];

        for (int i = 1; i < vec.size(); i++) {
            long long int a = vec[i][0], b = vec[i][1];

            if (a > r) {
                ans++;
                l = a;
                r = b;
            } else
                r = min(r, b);
        }
        return ans;
    }
};