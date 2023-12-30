class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> let(26,0);
        for(auto c: words)
            for(auto j:c) let[j-'a']++;
        for(int i=0;i<26;i++)
            if(let[i]%n) return false;

        return true;
    }
};