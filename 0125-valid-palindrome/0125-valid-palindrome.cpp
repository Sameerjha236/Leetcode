class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j=n-1;
        while(i<=j)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i] = tolower(s[i]);
            }
            if(s[j]>='A' && s[j]<='Z')
            {
                s[j] = tolower(s[j]);
            }
            if(!isalpha(s[i]) && !isdigit(s[i]))
            {
                i++;
                continue;
            }
            if(!isalpha(s[j]) && !isdigit(s[j]))
            {
                j--;
                continue;
            }
            // cout<<i<<" - "<<j<<" | "<<s[i]<<" - "<<s[j]<<" -> "<<s<<endl;
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        cout<<s;
        return true;
    }
};