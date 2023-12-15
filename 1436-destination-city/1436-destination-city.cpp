class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> hash;
        for(auto i: paths)
        {
            string a = i[0], b = i[1];
            hash[a]++;
            hash[b] = hash[b];
        }
        for(auto i: hash)
        {
            if(i.second == 0) return i.first;
        }
        return "";
    }
};