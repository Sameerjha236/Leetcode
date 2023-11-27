class Solution {
    int mod = 1e9 + 7;
    int solve(int i, int j, int n, vector<pair<int,int>> &moves,vector<vector<vector<int>>> &dp ,vector<vector<char>> &num)
    {
        if(i<0 || j<0 || j>2 || i>3 || num[i][j] == '*' || num[i][j] == '#') return 0;
        if(n == 0) return 1;
        if(dp[i][j][n] != -1) return dp[i][j][n];
        int ans = 0;
        for(auto k: moves)
        {
            int a = i + k.first, b = j + k.second;
            int curr = solve(a,b,n-1,moves,dp,num) % mod;
            ans += curr;
            ans = ans % mod;
        }
        return dp[i][j][n] = ans;
    }

public:
    int knightDialer(int n) {
        vector<vector<char>> num = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}, {'*', '0', '#'}};
        vector<pair<int,int>> moves = {{-2,-1}, {-2,1}, {-1,2}, {-1,-2}, {1,-2}, {1,2}, {2,-1}, {2,1}};

        long long int ans = 0;
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp (4, vector<vector<int>> (3, vector<int> (5001,-1)));
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int curr= (solve(i,j,n-1,moves,dp,num) % mod);
                ans += curr;
                ans = ans % mod;
                // cout<<num[i][j]<<" -> "<<curr<<endl;
            }
        }

        ans += (solve(3,1,n-1,moves,dp,num) % mod);
        ans = ans % mod;
        return ans;
    }
};