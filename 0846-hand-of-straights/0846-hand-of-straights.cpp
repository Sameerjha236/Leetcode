class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n = hand.size();
        map<int,int> hash;
        for(auto i: hand) hash[i]++;

        for(auto curr:hash)
        {
            int a = curr.first, freq = curr.second;
            while(freq)
            {
                int s = 0, k = a;
                while(s != g)
                {
                    if(hash[k] == 0)
                        return 0;
                    n--;
                    hash[k] = hash[k] - 1;
                    k++;
                    s++;
                }
                freq = hash[a];
            }
        }

        return n == 0;
    }
};