class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char,string> hash;
        hash['2']="abc";
        hash['3']="def";
        hash['4']="ghi";
        hash['5']="jkl";
        hash['6']="mno";
        hash['7']="pqrs";
        hash['8']="tuv";
        hash['9']="wxyz";

        for(auto i:digits)
        {
            if(ans.size()==0)
            {
                for(auto k:hash[i])
                {
                    string s;
                    s+=k;
                    ans.push_back(s);
                }
                continue;
            }
            vector<string> temp;
            for(auto k:hash[i])
            {
                for(auto j:ans)
                {
                    string s = j + k;
                    temp.push_back(s);
                }
            }
            ans = temp;
        }
        return ans;
    }
};