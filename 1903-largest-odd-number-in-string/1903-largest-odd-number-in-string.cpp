class Solution {
public:
    string largestOddNumber(string nums) {
        int  n = nums.size();
        string curr, ans;
        for(int i=0;i<n;i++)
        {
            curr += nums[i];
            int k = curr[curr.size() - 1] - '0';
            if(k%2)
                ans = curr;
        }
        return ans;
    }
};