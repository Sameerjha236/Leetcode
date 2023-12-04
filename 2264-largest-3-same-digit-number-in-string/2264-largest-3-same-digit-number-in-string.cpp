class Solution {
public:
    string largestGoodInteger(string nums) {
        int ans = -1, n = nums.size();
        string res;
        for(int i=0;i<n-2;i++)
        {
            if(nums[i] == nums[i+1] && nums[i] == nums[i+2])
            {
                string curr;
                curr += nums[i];
                curr += nums[i];
                curr += nums[i];
                int k = stoi(curr);
                if(k > ans)
                {
                    ans = k;
                    res = curr;
                }
            }
        }
        return res;
    }
};