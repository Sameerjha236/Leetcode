class Solution {

    bool helper(int i, int j, int k ,vector<vector<int>> &hr, vector<vector<int>> &vr, vector<vector<int>> &vec)
    {
        //left
        int a = i, b = j-k;
        if(vec[a][b] == 0 || (hr[i][j] - hr[a][b]) != k) return 0;
        //right
        b = j + k;
        if(vec[a][b] == 0 || (hr[a][b] - hr[i][j]) != k) return 0;
        //up
        b = j;
        a = i - k;
        if(vec[a][b] == 0 || (vr[i][j] - vr[a][b]) != k) return 0;
        //down
        a = i + k;
        if(vec[a][b] == 0 || (vr[a][b] - vr[i][j]) != k) return 0;

        return 1;
    }   

public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int tot = n * n;
        if(mines.size() == tot) return 0;
        vector<vector<int>> vec(n, vector<int>(n, 1));
        for (auto k : mines)
            vec[k[0]][k[1]] = 0;

        vector<vector<int>> hr(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            hr[i][0] = vec[i][0];
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                hr[i][j] = hr[i][j - 1] + vec[i][j];

        vector<vector<int>> vr(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            vr[0][i] = vec[0][i];
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                vr[i][j] = vr[i - 1][j] + vec[i][j];

        int ans = 1, l = 1, r = n / 2;
        while (l <= r) {
            int k = (l + r) / 2;
            bool got = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(i-k<0 || i +k >=n || j-k<0 || j+k>=n) continue;
                    if(vec[i][j] == 0) continue;
                    if (helper(i, j, k, hr,vr, vec)) {
                        got = 1;
                        break;
                    }
                }
            }
            if (got) {
                l = k + 1;
                ans = k + 1;
            } else {
                r = k - 1;
            }
        }
        return ans;
    }
};