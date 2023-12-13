class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int,pair<int,int>> hash;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                hash[mat[i][j]] = {i,j};
        }
        vector<int> r(m,n);
        vector<int> c(n,m);
        for(int i=0;i<arr.size();i++)
        {
            int k = arr[i];
            int x = hash[k].first;
            int y = hash[k].second;
            r[x]--;
            c[y]--;
            if(r[x] == 0 || c[y] == 0) return i;
        }
        return 0;
    }
};