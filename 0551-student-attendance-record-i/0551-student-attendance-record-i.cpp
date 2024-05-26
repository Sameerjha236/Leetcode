class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for (auto c : s) {
            if (c == 'L') {
                l++;
                if (l >= 3)
                    return 0;
            } else
                l = 0;
            if (c == 'A')
                a++;
            if (a >= 2)
                return 0;
        }
        return 1;
    }
};