class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r && s[l] == s[r]) {
            int a = l, b = r;
            while (s[a] == s[l] && a < r) {
                // cout << s[a];
                a++;
            }
            // cout << endl;
            while (s[b] == s[r] && b > l) {
                // cout << s[b];
                b--;
            }
            // cout << endl<<a<<" "<<b<<endl;
            l = a;
            r = b;

            // cout << s[l] << " " << s[r] << endl << endl;
        }
        return max(r - l + 1, 0);
    }
};