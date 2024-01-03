class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0,n = bank.size(), prev = -1;

        for(int i=0;i<n;i++)
        {
            string curr = bank[i];
            int k = count(curr.begin(),curr.end(),'1');
            if(k == 0) continue;
            if(prev == -1)
                prev = k;
            else
            {
                ans += prev * k;
                prev = k;
            }
        }

        return ans;
    }
};