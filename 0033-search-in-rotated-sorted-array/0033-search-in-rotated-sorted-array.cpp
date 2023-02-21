class Solution {
public:
    int search(vector<int>& vec, int target) {
        int n=vec.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int m= (low+high) >> 1;
            if(target == vec[m])
                return m;
            else if(vec[low]<=vec[m] )
            {
                if(vec[low]<=target && target<=vec[m])
                    high = m-1;
                else
                    low=m+1;
            }
            else
            {
                if(vec[m]<=target && target<=vec[high])
                    low=m+1;
                else
                    high = m-1;
            }
        }
        return -1;
    }
};