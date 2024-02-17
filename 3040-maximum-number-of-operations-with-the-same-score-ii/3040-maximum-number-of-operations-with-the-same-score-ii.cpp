class Solution {
private:
    int f(vector<int> &nums, int i, int j, int sum, vector<vector<int>> &dp) {
        if(i>=j) return 0;
        if(i+1 == j && nums[i]+nums[j] == sum) return 1; 
        if(dp[i][j] != -1) return dp[i][j];
        int choice1 = 0, choice2 = 0, choice3 = 0;
        if(nums[i] + nums[i+1] == sum) choice1 = 1+f(nums,i+2,j,sum,dp);
        if(nums[j] + nums[j-1] == sum) choice2 = 1 + f(nums,i,j-2,sum,dp);
        if(nums[j] + nums[i] == sum) choice3 = 1 + f(nums,i+1,j-1,sum,dp);
        return dp[i][j] = max(choice1,max(choice2,choice3));
    }
public:
    int maxOperations(vector<int>& nums) {
        int sum1 = nums[0]+nums[1];
        int sum2 = nums[0]+nums[nums.size()-1];
        int sum3 = nums[nums.size()-1]+nums[nums.size()-2];
        vector<vector<int>> dp1(nums.size(),vector<int>(nums.size(),-1));
        vector<vector<int>> dp2(nums.size(),vector<int>(nums.size(),-1));
        vector<vector<int>> dp3(nums.size(),vector<int>(nums.size(),-1));
        int ans1 = f(nums,0,nums.size()-1,sum1,dp1);
        int ans2 = f(nums,0,nums.size()-1,sum2,dp2);
        int ans3 = f(nums,0,nums.size()-1,sum3,dp3);
        return max(ans1,max(ans2,ans3));
    }
};