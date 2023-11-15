class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> prev(n, vector<int> (26,0));
        vector<vector<int>> forw(n, vector<int> (26,0));
        
        for(int i=1;i<n;i++)
        {
            char pre = s[i-1];
            prev[i] = prev[i-1];
            prev[i][pre - 'a']++;
        }

        for(int i=n-2;i>=0;i--)
        {
            char nex = s[i+1];
            forw[i] = forw[i+1];
            forw[i][nex - 'a']++;
        }
        int ans = 0;
        unordered_map<string,bool> check;

        for(int i=1;i<n-1;i++)
        {
            // cout<<i<<" -> \n";
            for(int j=0;j<26;j++)
            {
                if(forw[i][j] && prev[i][j])
                {
                    // cout<<char(j+'a')<<" -> "<<forw[i][j]<<" "<<prev[i][j]<<endl;
                    string curr;
                    curr += ('a'+j);
                    curr += s[i];
                    curr += ('a'+j);
                    if(check[curr]) continue;
                    check[curr] = 1;
                    ans++;
                }
            }
            // cout<<endl;
        }

        return ans;
    }
};