class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        vector<vector<int>> ans;
        map<int,vector<int>> store;
        for(int i=0;i<group.size();i++)
        {
            store[ group[i] ].push_back(i);
        }

        for(auto i:store)
        {
            int s = i.first,n = i.second.size();
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(i.second[j]);
                if(temp.size() == s)
                {
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }

        return ans;
    }
};