class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int a = num.length();
            for (int i = a - 1; i >= 0; i--) {
                if (num[i] % 2 ) {
                    ans = num.substr(0,i+1);
                    break;
                }
            }
        return ans;
    }
};