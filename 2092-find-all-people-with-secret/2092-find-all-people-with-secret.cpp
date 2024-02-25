#define pi pair<int, int>
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        vector<vector<pi>> G(n);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<bool> council(n, false);
        vector<int> res;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], time = meeting[2];
            G[x].push_back({time, y});
            G[y].push_back({time, x});
        }
        pq.push({0, 0});
        pq.push({0, firstPerson});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int time = p.first, person = p.second;

            if (council[person])
                continue;

            council[person] = true;

            for (auto& p : G[person]) {
                int nextTime = p.first, nextPerson = p.second;
                if (!council[nextPerson] && nextTime >= time)
                    pq.push(p);
            }
        }
        for (int i = 0; i < n; i++)
            if (council[i])
                res.push_back(i);
        return res;
    }
};