class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> hash;
        int n = nums.size(),curr=0,ans=0;
        for(int i=0;i<n;i++)
        {
            curr +=nums[i];
            if(curr == k)
                ans++;
            
            int check = curr - k;
            if(hash.find(check) !=hash.end())
            {
                ans+=hash[check];
            }
                hash[curr]++;

        }
        return ans;
    }
};