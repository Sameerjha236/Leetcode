class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int a,b,c;
        a = b = c = -1;
        int n = garbage.size();
        
        for(int i = 0; i<n;i++)
        {
            string curr = garbage[i];
            if(count(curr.begin(), curr.end(), 'M'))
                a = i;
            if(count(curr.begin(), curr.end(), 'P'))
                b = i;
            if(count(curr.begin(), curr.end(), 'G'))
                c = i;
        }
        int ans = 0, p = 0, q = 0, r = 0;
        for(int i=0;i<n;i++)
        {
            string curr = garbage[i];
            if(a != -1)
            {
                p += count(curr.begin(), curr.end(), 'M');
                if(a > i)
                    p += travel[i];
            }

            if(b != -1)
            {
                q += count(curr.begin(), curr.end(), 'P');
                if(b > i)
                    q += travel[i];
            }
            if(c != -1)
            {
                r += count(curr.begin(), curr.end(), 'G');
                if(c > i)
                    r += travel[i];
            }
        }
        ans = p + q + r;
        return ans; 
    }
};