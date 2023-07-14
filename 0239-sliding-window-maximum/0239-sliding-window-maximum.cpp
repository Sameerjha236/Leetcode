class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        while(j<n)
        {
            pq.push(make_pair(nums[j],j));
            if(j-i+1<k)
            {
                j++;
            }
            else
            {
                ans.push_back(pq.top().first);
                i++;
                j++;
                while(pq.top().second<i && j<n && !pq.empty())
                {
                    pq.pop();
                }

            }
        }
        return ans;
    }
};