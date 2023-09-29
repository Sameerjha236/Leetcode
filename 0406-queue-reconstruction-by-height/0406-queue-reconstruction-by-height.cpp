class Solution {
public:

    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        if(a[0]<b[0]) return 1;
        else if(a[0] == b[0])
        {
            if(a[1]<b[1]) return 1;
        }
        return 0;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),comp);
        vector<vector<int>> ans (n, vector<int> (2,-1));
        
        ans[nums[0][1]][0] = nums[0][0]; 
        ans[nums[0][1]][1] = nums[0][1]; 


        for(int i=1;i<n;i++)
        {
            int k = nums[i][1], st=0;

            // cout<<nums[i][0]<<" "<<nums[i][1]<<endl;
            for(int j=0;j<n;j++)
            {
                if(k)
                {
                    // cout<<"I ";
                    if(ans[j][0] == -1) k--;
                    else if(ans[j][0] == nums[i][0]) k--;
                }
                else if(ans[j][0] == -1)
                {
                    // cout<<"II ";
                    st = j;
                    break;
                }
            }
            // cout<<" -> "<<st<<endl;
            ans[st][0] = nums[i][0];
            ans[st][1] = nums[i][1];
        }

        return ans;
    }
};