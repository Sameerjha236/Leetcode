
class Solution
{
public:
    static bool myComp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    bool isPredecessor(string &wordI, string &wordJ)
    {
        int i = 0, j = 0;
        while (i < wordI.size())
        {
            if (j < wordJ.size() && wordI[i] == wordJ[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        return i == wordI.size() && j == wordJ.size();
    }
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), myComp);
        vector<int> dp(n, 1);
        int len = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (words[i].size() == words[j].size() + 1 &&
                    isPredecessor(words[i], words[j]) &&
                    dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    len = max(len, dp[i]);
                }
            }
        }
        return len;
    }
};