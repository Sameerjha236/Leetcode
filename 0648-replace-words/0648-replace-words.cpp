class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sen) {
        unordered_map<string, bool> hash;
        for (auto c : dictionary)
            hash[c] = 1;
        string ans, curr;
        int n = sen.size(), i = 0;

        while (i < n) {
            char c = sen[i];
            if (c == ' ') {
                ans += curr;
                ans += " ";
                curr = "";
                i++;
                continue;
            }
            curr += c;
            if (hash[curr]) {
                ans += curr;
                curr = "";
                while (i < n) {
                    if (sen[i] == ' ') {
                        ans += ' ';
                        i++;
                        break;
                    }
                    i++;
                }
            } else {
                i++;
            }
        }
        if(curr.size()) ans += curr;
        return ans;
    }
};