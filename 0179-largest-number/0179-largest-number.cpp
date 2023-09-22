class Solution {
public:

    static bool comp(long long int a, long long int b)
    {
        string first, second;
        first = to_string(a);
        second = to_string(b);
        string p, q;
        p = first + second;
        q = second + first;
        int n = p.size();
        for(int i=0;i<n;i++)
        {
            if(p[i] == q[i]) continue;
            if(p[i]>q[i]) return 1;
            else return 0;
        }
        return 0;
    }

    string largestNumber(vector<int>& nums) {
        string ans;
        vector<int> non;
        int z = 0;
        for(auto i:nums)
        {
            if(i !=0) non.push_back(i);
            else z++;
        }
        if(z == nums.size()) return "0";
        sort(non.begin(),non.end(),comp);
        for(auto ch:non)
        {
            string curr = to_string(ch);
            ans.append(curr);
        }
        while(z--) ans.push_back('0');
        return ans;
    }
};