class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) 
    {
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int a = arr.size(), m = arr[(a-1)/2], i=0, j=a-1;
        while(i<=j)
        {
            if(abs(arr[i]-m) > abs(arr[j]-m))
                ans.push_back(arr[i++]);
            else
                ans.push_back(arr[j--]);
        }
        return {ans.begin(), ans.begin()+k};
    }
};