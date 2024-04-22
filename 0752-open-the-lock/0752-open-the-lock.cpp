class Solution {

    vector<string> change = {"19", "02", "13", "24", "35",
                             "46", "57", "68", "79", "80"};

public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool> vis, end;

        for (auto k : deadends)
            end[k] = 1;
        if (end["0000"])
            return -1;

        vis["0000"] = 1;
        queue<string> q;
        q.push("0000");

        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string curr = q.front();
                q.pop();
                
                if (curr == target)
                    return ans;

                for (int i = 0; i < curr.size(); i++) {
                    int x = curr[i] - '0';
                    for (auto c : change[x]) {
                        string ch = curr;
                        ch[i] = c;
                        if (vis[ch] || end[ch])
                            continue;
                        vis[ch] = 1;
                        q.push(ch);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};