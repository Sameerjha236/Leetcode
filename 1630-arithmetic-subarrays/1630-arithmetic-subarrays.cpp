class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans;
        for(int i=0;i<m;i++)
        {
            int a = l[i], b = r[i];
            if(a == b || a == b - 1) ans.push_back(true);
            else
            {
                vector<int> curr(nums.begin() + a, nums.begin() + b + 1 );
                sort(curr.begin(), curr.end());
                int d = curr[1] - curr[0];
                bool c = 1;
                for(int j = 1; j<curr.size() - 1;j++)
                {
                    if(curr[j+1] - curr[j] != d) {
                        c = 0;
                        break;
                    }
                }
                if(c) ans.push_back(true);
                else ans.push_back(false);
            }
        }
        return ans;
    }
};