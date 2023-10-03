class Solution {
public:
    int minFlips(string target) {
        int ans = 0, n = target.size();
        char curr = '0';
        for(int i=0;i<n;i++)
        {
            if(curr == target[i]) continue;
            curr = target[i];
            ans++;
        }

        return ans;
    }
};