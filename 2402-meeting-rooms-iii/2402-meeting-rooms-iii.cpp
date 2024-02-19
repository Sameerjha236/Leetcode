static bool comp(vector<int>& a, vector<int>& b) {
    if (a[0] <= b[0])
        return 1;
    return 0;
}

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& vec) {
        sort(vec.begin(), vec.end(), comp);
        int m = vec.size();
        vector<long long> cnt(n, 0);
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            busy;

        for (int i = 0; i < n; i++)
            free.push(i);

        for (int i = 0; i < m; i++) {
            int st = vec[i][0], end = vec[i][1];

            while (!busy.empty() && busy.top().first <= st) {
                int k = busy.top().second;
                busy.pop();
                free.push(k);
            }

            if (!free.empty()) {
                int k = free.top();
                cnt[k]++;
                free.pop();
                busy.push({end, k});
            } else {
                long long a = busy.top().first, k = busy.top().second;
                cnt[k]++;
                busy.pop();
                long long diff = a - st;
                busy.push({end + diff, k});
            }
        }
        int ans = 0, val = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > val) {
                ans = i;
                val = cnt[i];
            }
        }
        return ans;
    }
};