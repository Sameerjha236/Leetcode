class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k>=n)
            return *max_element(arr.begin(),arr.end());
        int curr = 0, ans = 0, val = 0;
        deque<int> q;
        for(auto i:arr) q.push_back(i);
        while(ans !=k)
        {
            int a = q.at(0);
            int b = q.at(1);
            int c = 0;
            if(a > b)
            {
                q.pop_front();
                q.pop_front();
                q.push_front(a);
                q.push_back(b);
                c = a;
            }
            else
            {
                q.pop_front();
                q.push_back(a);
                c = b;
            }
            if(val == c)
            {
                curr ++;
            }
            else
            {
                val = c;
                curr = 1;
            }
            ans = max(ans,curr);
        }
        return val;
    }
};