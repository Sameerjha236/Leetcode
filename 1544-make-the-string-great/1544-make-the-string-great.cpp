
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (auto c : s) {
            int k = 0;
            bool up = 0;
            if (c >= 'a' && c <= 'z')
                k = c - 'a';
            else {
                k = c - 'A';
                up = 1;
            }
            if (!st.empty()) {
                char b = st.top();
                if (up && b >= 'a' && b <= 'z' && (b - 'a') == k) {

                    st.pop();
                } else if (up == 0 && b >= 'A' && b <= 'Z' && (b - 'A') == k) {

                    st.pop();
                }
                else st.push(c);
            }
            else st.push(c);

        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};