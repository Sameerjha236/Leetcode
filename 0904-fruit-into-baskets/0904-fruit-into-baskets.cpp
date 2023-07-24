class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(),ans=0;
        int i=0,j=0;
        unordered_map<int,int> hash;
        while(j<n)
        {
            int k = fruits[j];
            hash[k]++;
            while(hash.size()>2)
            {
                hash[fruits[i]]--;
                if(hash[fruits[i]]==0)
                    hash.erase(fruits[i]);
                i++;
           }
            ans = max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};