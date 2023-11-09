class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(m>n) return "";
        unordered_map<char,int> store;
        for(auto i:t) store[i]++;

        int st = 0, end = 0, ln = INT_MAX, si  = -1, count = 0;

        for(int end=0;end<n;end++)
        {
            if(store[s[end]] > 0) count++;
            store[s[end]]--;

            if(count == m)
            {
                while(st<end && store[s[st]]<0)
                {
                    store[s[st]]++;
                    st++;
                }

                if(ln > (end - st +1))
                {
                    ln = end - st + 1;
                    si = st;
                }
                store[s[st]]++;
                st ++;
                count--;
            }
        }
        if(ln == INT_MAX) return "";
        return s.substr(si, ln);
    }
};