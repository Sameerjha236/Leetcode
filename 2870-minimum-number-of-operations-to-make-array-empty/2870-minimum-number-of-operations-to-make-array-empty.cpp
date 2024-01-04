class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        int c=0;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto j:mp)
        {
            if(j.second==1)
                return -1;   
            else if(j.second%3==0)
                c=c+(j.second/3);
            else
                c=c+(j.second/3)+1;
        }
        return c;
    }
};