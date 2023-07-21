class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<int> vis(n);
        vis[start] = 1;

        while(q.size()) {
            int idx = q.front(); q.pop();
            vis[idx]=1;
            if(!arr[idx]) return true;

            if(idx + arr[idx] < n && !vis[idx + arr[idx]]) {
                q.push(idx + arr[idx]);
            }
            if(idx - arr[idx] >= 0 && !vis[idx - arr[idx]]) {
                q.push(idx - arr[idx]);
            }
        }
        return false;
    }
};