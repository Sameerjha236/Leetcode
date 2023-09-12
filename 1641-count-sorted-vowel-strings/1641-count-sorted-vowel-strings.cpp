class Solution {
public:

    int solve(int s, int n, int ind)
    {
        if(s == n) return 5 - ind + 1;
        if(ind == 5) return 1;

        int ans = 0;
        for(int i = ind;i<=5;i++)
        {
            int curr = solve(s+1,n,i);
            ans += curr;
        }
        return ans;
    }

    int countVowelStrings(int n) {
        int ans = 0;
        ans = solve(1,n,1);
        return ans;
    }
};