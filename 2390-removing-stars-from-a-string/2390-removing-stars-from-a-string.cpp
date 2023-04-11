class Solution {
public:
    string removeStars(string s) {
        string store;
        for(auto i:s)
        {
            if(i=='*') store.pop_back();
            else store+=i;
        }
        return store;
    }
};