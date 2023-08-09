class Solution {
public:
    int minSteps(string s, string t) 
    {
        if (s.size() != t.size())       return -1;
        vector<int> count(26, 0); 
        for (char c : s)        count[c - 'a']++;// itna material chahiye
        for (char c : t)        count[c - 'a']--;// itna material hai 
        int steps = 0;
        for (int val : count)
                if (val > 0)    steps += val;
        return steps;
    }
};