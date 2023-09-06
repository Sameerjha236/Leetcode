class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> store;
        for(auto i:s) store[i]++;
        int ans = 0,a=0;
        for(auto i:store)
        {
            if(i.second%2 == 1) a=1;
            if(i.second>1)
            {
                if(i.second%2 == 0) ans +=i.second;
                else ans += i.second-1;
            }
        }
        if(a) ans ++;
        return ans;
    }
};