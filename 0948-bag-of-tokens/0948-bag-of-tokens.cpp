class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1, res = 0, curr = 0;
        while (l <= r) {
            if (tokens[l] <= power) {
                power -= tokens[l];
                l++;
                curr++;
                res = max(res,curr);
            } else if (curr) {
                curr--;
                power += tokens[r];
                r--;
            }
            else break;
        }
        return res;
    }
};