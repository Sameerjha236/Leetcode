class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto i:nums) hash[i]++;
        int unique = hash.size();
        hash.clear();
        int i=0,j=0,ans=0,n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                hash[nums[j]]++;
                if(hash.size() == unique)
                    ans++;
            }
            hash.clear();
        }
        return ans;
    }
};