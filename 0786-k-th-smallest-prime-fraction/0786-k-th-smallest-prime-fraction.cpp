#define pi pair<int, int>
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<double, pi> hash;
        priority_queue<double, vector<double>, greater<double>> pq;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double a = arr[i], b = arr[j];
                double val = a / b;
                hash[val] = {a, b};
                pq.push(val);
            }
        }
        while (k--) {
            double val = pq.top();
            // cout<<val<<" ";
            if (k == 0) {
                return {hash[val].first, hash[val].second};
            }
            pq.pop();
        }
        return {};
    }
};