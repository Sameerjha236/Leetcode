class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> store;
        int sdMax = INT_MIN, n = nums.size();

        for(int i=n-1;i>=0;i--)
        {
            int k = nums[i];
            if(k<sdMax) return true;
            while(!store.empty() && store.top()<k)
            {
                sdMax = store.top();
                store.pop(); 
            }
            store.push(k);
        }
        return 0;
    }
};