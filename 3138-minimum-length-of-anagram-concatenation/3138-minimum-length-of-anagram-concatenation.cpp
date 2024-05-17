class Solution {
public:
    int minAnagramLength(string str) {
        int n = str.size();
        for(int s=1;s<=n;s++)
        {
            if(n%s != 0)
                continue;
            vector<int> curr(26,0);
            map<vector<int>, int> hash;
            int i = 0, j = 0;
            while(j<n)
            {
                char c = str[j];
                curr[c-'a']++;   
                if(j - i + 1 == s)
                {
                    hash[curr]++;
                    vector<int> tp(26,0);
                    curr = tp;
                    j++;
                    i = j;
                }
                else j++;
            }
            if(hash.size() == 1)
                return s;
        }
        return 1;
    }
};