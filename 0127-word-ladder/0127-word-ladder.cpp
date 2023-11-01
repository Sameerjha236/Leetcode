class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
        set<string> st (word.begin(), word.end());
        if(st.find(end) == st.end()) return 0;
        queue<pair<string,int>> q;
        q.push({begin,1});
        st.erase(begin);

        while(!q.empty())
        {
            string curr = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(curr == end) return lvl;
            for(int i=0;i<curr.size();i++)
            {
                char t = curr[i];
                for(char k='a'; k<='z'; k++)
                {
                    curr[i] = k;
                    if(st.find(curr) != st.end())
                    {
                        q.push({curr,lvl+1});
                        st.erase(curr);
                    }
                }
                curr[i] = t;
            }
        }

        return 0;
    }
};