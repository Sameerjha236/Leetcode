class Solution {

    bool helper(int i, int j, int k, vector<vector<int>>& cons,
                vector<vector<char>>& vec) {

        for (int p = i; p <= i + k; p++) {
            int a = cons[p][j], b = cons[p][j + k];
            if (vec[p][j] == '0' || vec[p][j + k] == '0')
                return 0;
            if (b - a < k)
                return 0;
        }
        return 1;
    }

public:
    int maximalSquare(vector<vector<char>>& vec) {
        int m = vec.size(), n = vec[0].size();

        bool cnt = 0;
        for (auto i : vec) {
            for (auto j : i) {
                if (j == '1') {
                    cnt = 1;
                    break;
                }
            }
            if (cnt)
                break;
        }
        if (cnt == 0)
            return 0;
        vector<vector<int>> cons(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            cons[i][0] = (vec[i][0] - '0');

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cons[i][j] = cons[i][j - 1] + (vec[i][j] - '0');
            }
        }

        int l = 1, r = min(m, n), ans = 0;
        while (l <= r) {
            int k = (l + r) / 2;
            bool got = 0;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i + k >= m || j + k >= n)
                        continue;

                    if (helper(i, j, k, cons, vec)) {
                        got = 1;
                        break;
                    }
                }
            }
            if (got) {
                l = k + 1;
                ans = (k + 1) * (k + 1);
            } else {
                r = k - 1;
            }
        }

        return max(ans, 1);
    }
};