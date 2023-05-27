class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> temp(2);
        sort(intervals.begin(),intervals.end());
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            int a = intervals[i][0];
            int b = intervals[i][1];

            if((temp[0]<=a && a<=temp[1]) || (temp[0]<=b && b<=temp[1]))
            {
                temp[1] = max(temp[1],b);
                temp[0] = min(temp[0],a);
            }
            else
            {
                ans.push_back(temp);
                temp[0] = a;
                temp[1] = b;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};