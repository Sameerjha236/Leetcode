class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        set<int> st;
        while(j<n)
        {
            int curr = nums[j];
            if(st.find(curr) !=st.end())
            {
                return 1;
            }
            st.insert(curr);
            if(j-i<k)
            {
                j++;
            }
            else
            {
                st.erase(nums[i]);
                i++;
                j++;
            }
        }
        return 0;
    }
};