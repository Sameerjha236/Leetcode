class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> store;
        vector<int> check(n,1);
        store.push(0);
        check[0] = 0;
        while(!store.empty())
        {
            int k = store.front();
            store.pop();
            n--;
            for(auto i:rooms[k])
            {
                if(check[i])
                {
                    store.push(i);
                    check[i] = 0;
                }
            }
        }

        return n == 0;
    }
};