class Solution {
public:
    bool check(string& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
            if (s[i] != s[n - 1 - i])
                return 0;
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        for (auto i : words)
            if (check(i))
                return i;
        return "";
    }
};