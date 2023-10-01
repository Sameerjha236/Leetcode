class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n+1),suffix(n+1);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        int sum=0;
        for(int i=1;i<nums.size()-1;i++)
        {
            prefix[i]=max(prefix[i-1],nums[i]);
        }
         for(int i=n-2;i>=0;i--)
        {
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]>prefix[i-1]&&nums[i]<suffix[i+1])
            sum+=2;
            else if (nums[i-1]<nums[i]&&nums[i]<nums[i+1])
            sum+=1;
        }
        return sum;
        
    }
};