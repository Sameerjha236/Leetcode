class Solution {
public:
    struct Job {
        int start;
        int end;
        int profits;
    };

    bool static compare(Job a, Job b) { return a.start < b.start; }

    int findNextIndex(int ind, int n, struct Job* jobs) {
        int prev = jobs[ind].end;
        int low = ind + 1, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid].start < prev) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        struct Job* jobs = new struct Job[n];
        for (int i = 0; i < n; i++) {
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profits = profit[i];
        }
        sort(jobs, jobs + n, compare);
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int nxtIndex = findNextIndex(i, n, jobs);
            dp[i] = max(jobs[i].profits + dp[nxtIndex], dp[i + 1]);
        }
        return dp[0];
    }
};