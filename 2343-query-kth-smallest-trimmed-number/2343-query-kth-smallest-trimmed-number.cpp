static bool comp(pair<string, int>& a, pair<string, int>& b) {

    int m = a.first.size();

    for (int i = 0; i < m; i++) {
        int x = a.first[i] - '0', y = b.first[i] - '0';

        if (x < y)
            return 1;
        else if (y < x)
            return 0;
    }
    return a.second < b.second;
}
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                       vector<vector<int>>& q) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < q.size(); i++) {
            int k = q[i][0], x = q[i][1];
            vector<pair<string, int>> tp;

            for (int j = 0; j < n; j++) {
                string c = nums[j];
                int m = c.size();
                string curr = c.substr(m - x);
                tp.push_back({curr, j});
            }

            sort(tp.begin(), tp.end(), comp);

            ans.push_back(tp[k - 1].second);
        }

        return ans;
    }
};