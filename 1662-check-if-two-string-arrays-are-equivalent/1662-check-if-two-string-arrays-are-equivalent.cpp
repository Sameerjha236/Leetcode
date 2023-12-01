
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a, b;
        

        for(const auto& x : word1)
            a += x;

        
        for(const auto& x : word2)
            b += x;


        return a == b;
    }
};