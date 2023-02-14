class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		set<char> st;
		int i = 0, j = 0, n = s.size(), ans = 0;
		for(int i=0;i<n;i++) 
        {
            while(st.count(s[i]))
            {
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
            if(st.size()>ans)
                ans=st.size();
        }
		return ans;
	}
};