class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> store;
        int fact=1;
        for(int i=1;i<n;i++)
        {
            fact *=i;
            store.push_back(i);
        }   
        store.push_back(n);
        k = k-1;
        while(true)
        {
            ans = ans + to_string( store[k/fact] );
            store.erase(store.begin()+ k/fact);
            if(store.size()==0) break;
            k = k % fact;
            fact = fact / store.size();
        }
        return ans;
    }
};