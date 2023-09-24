class Solution {
public:
    double champagneTower(int amt, int qr, int qc) {
        if(amt<1) return 0;
        double ans=0;
        int i = 0;
        vector<vector<double>> store;
        store.push_back({double(amt)});
        while(i<qr)
        {
            int c = (i+2);
            vector<double> tp(c,0);
            store.push_back(tp);
            for(int j=0;j<=i;j++)
            {
                if(store[i][j]<=1) continue;
                int l = j, r = j+1;
                double exc = store[i][j] - 1;
                store[i][j] = 1;
                exc /= 2;
                store[i+1][l] += exc;
                store[i+1][r] += exc;
            }
            i++;
        }
        
        ans = store[qr][qc];
        if(ans>1) ans=1;
        return ans;
    }
};