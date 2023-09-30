class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<=2) return 0;
        stack<pair<int,int>> store;
        int currMin = nums[0], n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            int j = nums[i];
            while(!store.empty() && store.top().first <= j)
                store.pop();
            
            if(!store.empty() && j > store.top().second)
                return 1;
            store.push(make_pair(j,currMin));
            currMin = min(currMin, j);
        }

        return 0;
    }
};