class Solution
{
public:
    void backtrack(vector<int> &count, int &res)
    {
        for (int i = 0; i < count.size(); i++)
        {
            if (count[i] > 0)
            {
                res++;
                count[i]--;
                backtrack(count, res);
                count[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles)
    {
        unordered_map<char, int> m;
        for (const auto &it : tiles)
            m[it]++;
        vector<int> count;
        for (const auto &it : m)
            count.emplace_back(it.second);
        int res = 0;
        backtrack(count, res);
        return res;
    }
};