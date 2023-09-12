
class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
    vector<int> count(26);
    unordered_set<int> st;

    for (const char c : s)
      ++count[c - 'a'];

    for (int freq : count)
    {
        while(freq>0)
        {
          if(st.find(freq) == st.end())
          {
            st.insert(freq);
            break;
          }
          freq--;
          ans++;
        }
    }

    return ans; 
    }
};