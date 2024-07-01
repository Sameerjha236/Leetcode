class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int c = 0;
        for (auto i : arr) {
            if (i % 2 == 1)
                c++;
            else
                c = 0;
            if (c > 2)
                return 1;
        }
        return 0;
    }
};