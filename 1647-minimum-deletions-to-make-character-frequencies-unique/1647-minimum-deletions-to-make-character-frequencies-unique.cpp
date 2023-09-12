class Solution {
public:
    int minDeletions(string s) {
        if(!s.size()) return 0;
        
        unordered_map<char,int> chac;
        for(auto i:s) chac[i]++;

        map<int,int> num;
        for(auto k:chac)
        {
            num[k.second] ++;
        }
        int ans = 0;
        for(auto f:num)
        {
            int val = f.first, freq = f.second;
            for(int i=freq; i>1;i--)
            {
                for(int j=val;j>=0;j--)
                {
                    if(j == 0) ans += val;
                    else if(num[j]==0)
                    {
                        ans += val - j;
                        num[j]++;
                        break;
                    }

                }
            }
        }
        sort(s.begin(),s.end());
        cout<<s<<endl;
        return ans;
    }
};