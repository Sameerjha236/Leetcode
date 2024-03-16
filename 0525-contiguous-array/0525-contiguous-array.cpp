class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> hash;
        int z = 0, o = 0, n = nums.size(), ans = 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]) o++;
            else z++;

            if(z == o)
            {
                ans = max(ans,i+1);
            }
            else if(hash.find(o-z) != hash.end())
            {
                ans = max(ans,i-hash[o-z]);
            }
            
            if(hash.find(o - z) == hash.end())
            {
                hash[o-z] = i;
            }
        }

        return ans;
    }
};