
class Solution
{
public:
    bool check(string p, string q)
    {
        int m = p.size(), n = q.size();
        bool k = 0;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (p[i] == q[j])
            {
                i++;
                j++;
            }
            else if (k == 0)
            {
                k=1;
                j++;
            }
            else
                return 0;
        }
        return 1;
    }

    int helper(string p, int k, unordered_map<int, vector<string>> &hash, unordered_map<string, int> &store)
    {
        int curr = 0;
        for (auto q : hash[k])
        {
            if (check(p, q))
            {
                int tp = 0;
                if(store[q] != -1) tp = store[q];
                else tp = helper(q, q.size() + 1, hash, store);
                curr = max(tp+1, curr);
            }
            else cout<<endl;
        }
        return max(curr, 1);
    }

    int longestStrChain(vector<string> &words)
    {
        int ans = 1;
        unordered_map<int, vector<string>> hash;
        unordered_map<string, int> store;

        for (auto k : words)
        {
            hash[k.size()].push_back(k);
            store[k] = -1;
        }

        vector<int> len;
        for(auto k:hash) len.push_back(k.first);
        sort(len.begin(),len.end(),greater<int>());

        for(auto l:len)
        {
            for(auto j: hash[l])
            {
                int curr = helper(j, l + 1, hash,store);
                cout<<j<<" "<<curr<<endl; 
                store[j] = curr;
                ans = max(curr, ans);
            }
            cout<<endl;
        }

        return ans;
    }
};