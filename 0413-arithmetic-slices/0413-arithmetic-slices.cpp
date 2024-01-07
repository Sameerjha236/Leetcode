class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return 0;
        int ans = 0;
        for(int i=0;i<n-2;i++)
        {
            int d = arr[i+1] - arr[i];
            for(int j=i+2;j<n;j++)
            {
                int c = arr[j] - arr[j-1];
                if(c == d)
                    ans++;
                else break;
            }
        }

        return ans;
    }
};