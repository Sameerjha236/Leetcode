class Solution {
    unordered_map<int,int> hash;

    int helper(int i,vector<int> &dp, vector<int> & nums)
    {
        int n = nums.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int tk = 0, nt = 0, curr = nums[i];
        int f = hash[curr];
        int nx = i + f;

        nt = helper(nx,dp,nums);
        if(hash[curr+1]) nx += hash[curr+1];
        tk = curr * f + helper(nx,dp,nums);

        // cout<<curr<<" "<<tk<<" "<<nt<<endl;
        return dp[i] = max(tk,nt);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(auto i: nums) hash[i]++;
        int ans = 0;
        vector<int> dp(n,-1);
        ans = helper(0,dp,nums);
        return ans;
    }
};