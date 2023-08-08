class Solution {
public:
    int search(vector<int>& vec, int target) {
        int n = vec.size();
        int l = 0,r=n-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(vec[m] == target) return m;

            if(vec[l]<=vec[m])
            {
                if(vec[l]<= target && vec[m]>=target)
                    r = m-1;
                else l = m+1;
            }
            else
            {
                if(vec[m]<= target && vec[r]>=target)
                    l = m+1;
                else r = m-1;
            }
        }
        return -1;
    }
};