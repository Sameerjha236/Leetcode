class Solution {

    int solve(int i, vector<int> st, vector<string> &arr)
    {
        if(i == arr.size()) return 0;
        int tk = 0, nt = 0;
        nt = solve(i+1,st,arr);
        bool chk = 1;
        for(auto l: arr[i])
        {
            if(st[l-'a'])
            {
                chk = 0;
                break;
            }
            else st[l-'a'] = 1;
        }
        if(chk)
        {
            tk = arr[i].size() + solve(i+1,st,arr);
        }
        return max(tk,nt);
    }

public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        vector<int> st(26,0);
        ans = solve(0,st,arr);
        return ans;
    }
};