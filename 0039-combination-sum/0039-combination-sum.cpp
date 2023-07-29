class Solution {
public:

    void solve(vector<int> &nums,int k, int ind, vector<int> ds, vector<vector<int>> &answer)
    {
        if(k==0)
        {
            answer.push_back(ds);
        }
        for(int i=ind;i<nums.size();i++)
        {
            if(nums[i]<=k)
            {
                ds.push_back(nums[i]);
                solve(nums,k-nums[i],i,ds,answer);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        vector<int> ds;
        solve(nums,k,0,ds,answer);
        return answer;
    }
};