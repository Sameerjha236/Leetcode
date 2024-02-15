class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(auto i: nums){
            ans+=i;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(i<2) return -1;
            if(ans-nums[i]>nums[i]) return ans;
            else ans-=nums[i];
        }
        return -1;
    }
};