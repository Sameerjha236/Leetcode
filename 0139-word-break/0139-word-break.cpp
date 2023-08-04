class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> vis(s.length() + 1, 0);
        unordered_map<string, int> mp;
        for (const auto& word : wordDict) 
        {
            mp[word]++;
        }
        vis[0] = 1;
        for (int i = 0; i < s.length(); i++) 
        {
            if (vis[i]) 
            {
                for (int j = i; j < s.length(); j++) 
                {
                    string substr = s.substr(i, j - i + 1); 
                    if (mp.find(substr) != mp.end()) 
                    {
                        vis[j + 1] = 1;
                    }
                }
            }
        }
        return vis[s.length()];
    }
};