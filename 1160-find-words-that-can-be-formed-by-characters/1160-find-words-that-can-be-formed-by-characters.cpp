class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        for(auto w: words)
        {
            bool c = 1;
            for(char a='a'; a<='z';a++)
            {
                if(count(chars.begin(), chars.end(), a) < count(w.begin(), w.end(), a))
                {
                    c = 0 ;
                    break;
                }
            }
            if(c) ans+= w.size();
        }
        return ans;
    }
};