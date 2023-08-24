class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> store;
        int n = s.size();
        int k = 0;
        if(n%2) k = n/2 +1;
        else k = n/2;
        for(auto c:s)
        {
            store[c]++;
            if(store[c] > k) return "";
        }
        priority_queue<pair<int,char>> pq;
        for(auto i:store)
            pq.push(make_pair(i.second,i.first));
        k=0;
        while(!pq.empty())
        {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            while(freq--)
            {
                if(k>=n) k=1;
                s[k] = ch;
                k+=2;
            }
        }
        return s;
    }
};