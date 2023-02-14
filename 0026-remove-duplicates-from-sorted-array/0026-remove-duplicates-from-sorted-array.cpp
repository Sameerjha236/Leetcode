class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a=0;
        a++;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            nums[a]=nums[i];
            a++;
        }
        return a;
    }
};