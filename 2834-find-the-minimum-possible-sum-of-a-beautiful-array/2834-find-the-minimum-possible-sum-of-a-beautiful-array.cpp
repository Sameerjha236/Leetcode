class Solution {
public:

    long long minimumPossibleSum(int n, int target) {
        long long ans = 0,curr=1,cnt=0;
        unordered_map<int,bool> store;
        while(cnt < n)
        {
            int k = target - curr;
            if(store[k])
            {
                curr++;
                continue;
            }
            cnt++;
            ans += curr;
            store[curr] = 1;
            curr++;
        }
        return ans;
    }
};