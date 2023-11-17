class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& vec) {
        sort(vec.begin(), vec.end());
        int prev = vec[0] = 1, n = vec.size();
        for(int i=1;i<n;i++)
        {
            if(vec[i] > prev+1)
            {
                vec[i] = prev + 1;
                prev = vec[i];
            }
            else prev = vec[i];
        }
        // for(auto i:vec) cout<<i<<" ";
        return vec[vec.size() - 1];
    }
};