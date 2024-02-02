class Solution {
    set<int> st;

    void solve(int i, int k,string ds, int low, int high)
    {
        while(k<=9 && i<ds.size())
        {
            ds[i] = '0' + k;
            i++;
            k++;
        }
        long long int curr = stoll(ds);
        if(i==ds.size() && curr>=low && high>= curr)
        {
            st.insert(curr);
        }
    }

public:
    vector<int> sequentialDigits(int low, int high) {
        string r = to_string(high);
        int n = r.size();
        string ds;
        for(int i=0;i<n;i++) ds +='0';

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=9;j++)
            {
                solve(i,j,ds,low,high);
            }
        }
        vector<int> ans;
        for(auto i:st) ans.push_back(i);
        return ans;
    }
};