
class Solution
{
public:
    static bool comp(const pair<int, long long int> &a, const pair<int, long long int> &b)
    {
        if (a.first > b.first)
            return 1;
        else if(a.first == b.first) 
            return a.second < b.second;
        return 0;
    }

    vector<int> topStudents(vector<string> &pF, vector<string> &nF, vector<string> &rep, vector<int> &id, int k)
    {
        int n = id.size();

        unordered_map<string, int> points;
        for (auto i : pF)
            points[i] = 3;
        for (auto i : nF)
            points[i] = -1;

        vector<pair<int, long long int>> store;
        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            string w;
            for (int j = 0; j < rep[i].size(); j++)
            {
                char c = rep[i][j];
                if (c == 32 && w.size())
                {
                    int s = points[w];
                    curr += s;
                    w = "";
                }
                else
                    w += c;
            }
            if (w.size())
            {
                int s = points[w];
                curr += s;
            }
            // cout<<curr<<" "<<id[i]<<endl;
            store.push_back(make_pair(curr, id[i]));
        }

        vector<int> ans;
        sort(store.begin(), store.end(), comp);
        // for(auto i:store)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        for (int i = 0; i < k; i++)
        {
            ans.push_back(store[i].second);
        }
        return ans;
    }
};