class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& vec) {
        int n = vec.size();
        unordered_map<int,vector<int>> store;
        for(auto i: vec)
        {
            store[i[0]].push_back(i[1]);
            store[i[1]].push_back(i[0]);
        }

        vector<int> ans(n+1,-1);
        unordered_map<int,int> vis;
        for(auto i: store)
        {
            if(i.second.size() == 1)
            {
                vis[i.first] = 1;
                    ans[0] = i.first;
                break;
            }
        }
        int i = 0;
        while(i<n)
        {
            int nex = i + 1;
            int val = ans[i];
            for(auto k: store[val])
            {
                if(vis[k] == 0)
                {
                    ans[nex] = k;
                    vis[k] = 1;
                }
            }
            i++;
        }

        return ans;
    }
};