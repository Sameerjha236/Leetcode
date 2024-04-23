class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }

        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }

        while (n > 2) {
            int numLeaves = leaves.size();
            n -= numLeaves;

            for (int i = 0; i < numLeaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();

                for (int neighbor : adj[leaf]) {
                    if (--degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }
};
