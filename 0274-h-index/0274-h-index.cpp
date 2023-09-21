class Solution {
public:
    int hIndex(vector<int>& vec) {
        map<int,int> hash;
        int m=0;
        for(auto k:vec)
        {
            hash[k]++;
            m = max(k,m);
        } 
        int n = vec.size();
        vector<int> store(m+1,0);

        for(int i=m;i>=0;i--)
        {
            int k = 0;
            if(i<m) k = store[i+1];
            store[i] = hash[i] + k;
            if(store[i]>=i)
                return i;
        }
        return 0;
    }
};