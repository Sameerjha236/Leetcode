class Solution {
    string ans;

    void solve(int i, string tp, unordered_map<string,bool> &hash)
    {
        if(hash[tp] == 0)
        {
            ans = tp;
            return;
        }
        if(i == tp.size()) return;
        
        // not take
        solve(i+1,tp,hash);
        // take
        tp[i] = '1';
        solve(i+1,tp,hash);
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<string,bool> hash;
        for(auto i:nums) hash[i] = 1;
        string tp;
        for(int i=0;i<n;i++) tp.push_back('0');
        solve(0,tp,hash);
        return ans;
    }
};