class Solution {
public:
    bool canFinish(int sub, vector<vector<int>>& pre) {
        vector<int> dep(sub,0);
        unordered_map<int,vector<int>> hash;
        unordered_map<int,vector<int>> det;

        for(auto i:pre)
        {
            dep[i[0]]++;
            hash[i[1]].push_back(i[0]);
            det[i[0]].push_back(i[1]);
        }
        queue<int> store;
        for(int i=0;i<sub;i++)
        {
            if(dep[i]) continue;
            store.push(i);
        }
        
        while(!store.empty())
        {
            int curr = store.front();
            dep[curr] = 0;
            store.pop();
            sub--;
            for(auto k:hash[curr])
            {
                if(dep[k] == 0) continue;
                bool ck = 1;
                for(auto i:det[k])
                {
                    if(dep[i] == 0) continue;
                    ck = 0;
                    break;
                }
                if(ck == 0) continue;
                store.push(k);
                dep[k] = 0;
            }
        }
        if(sub <= 0) return true;

        return false;
    }
};