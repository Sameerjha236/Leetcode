class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r && s[l] == s[r]) {
            int a = l, b = r;
            while (s[a] == s[l] && a < r)

                a++;

            while (s[b] == s[r] && b > l)
                b--;

            l = a;
            r = b;
        }
        return max(r - l + 1, 0);
    }
};