class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)return 1;
        map<int,int>mp;
        map<int,int>m;
        for(int i=0;i<trust.size();i++){
            mp[trust[i][0]]++;
            m[trust[i][1]]++;
        }
      
        for(auto x:m){
            if(mp[x.first]==0 && x.second==n-1){
                return x.first;
            }
        }
        return -1;
    }
};