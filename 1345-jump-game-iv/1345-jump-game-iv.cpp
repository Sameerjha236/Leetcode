class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()==1) return 0;
        int ans=0, n=arr.size();
        map<int,vector<int>> hash;
        vector<int> vis(n,1);
        for(int i=0;i<n;i++)
        {
            hash[arr[i]].push_back(i);
        }
        queue<int> store;
        store.push(0);
        while(!store.empty())
        {
            ans++;
            int k = store.size();
            for(int i=0;i<k;i++)
            {
                int curr = store.front();
                store.pop();
                if(curr == n-1) return ans-1;
                int val = arr[curr];
                vis[curr]=0;
                if(curr - 1 >=0 && vis[curr-1])
                {
                    store.push(curr-1);
                    vis[curr-1]=0;
                }
                if(curr + 1 <n && vis[curr+1])
                {
                    store.push(curr+1);
                    vis[curr+1]=0;
                }
                if(!hash[val].size()) continue;
                
                vector<int> tp = hash[val];
                hash.erase(val);
                for(auto j:tp)
                {
                    if(!vis[j]) continue;
                    store.push(j);
                    vis[j]=0;
                }
            }
        }
        return ans;
    }
};