class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
      unordered_set<string> prefixSuffixGroup[26];
      for (auto& idea: ideas) prefixSuffixGroup[idea[0] - 'a'].insert(idea.substr(1));
      long long ans = 0;
      for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 26; j++) {
          int mutualSuffixCount = 0;
          for (auto& s : prefixSuffixGroup[i]) {
            if (prefixSuffixGroup[j].count(s) == 1) mutualSuffixCount ++;
          }

          ans += 2LL * (prefixSuffixGroup[j].size() - mutualSuffixCount) * (prefixSuffixGroup[i].size() - mutualSuffixCount);
        }
      }

      return ans;
    }
};