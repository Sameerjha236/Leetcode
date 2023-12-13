class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;

        for(int i=0;i<m;i++)
        {
            int o = 0, p = -1;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j])
                {
                    o++;
                    p = j;
                }
            }
            if(o == 1)
            {
                o = 0;
                for(int j = 0;j<m;j++)
                    if(mat[j][p]) o++;


                if(o == 1) ans++;
            }
        }

        return ans;
    }
};