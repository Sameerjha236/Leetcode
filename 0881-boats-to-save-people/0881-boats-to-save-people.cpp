class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0, i = 0, j = people.size() - 1, n = people.size();
        while(i<=j)
        {
            int a = people[i], b = people[j];
            if(a+b<=limit)
            {
                i++;
                j--;
                ans++;
                continue;
            }
            j--;
            ans++;
        }
        return ans;
    }
};