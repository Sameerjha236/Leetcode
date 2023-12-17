class FoodRatings {
public:
    map<string,pair<int,string>> hash;
    map<string,set<pair<int,string>>> store;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++)
        {
            string f = foods[i], c = cuisines[i];
            int r = ratings[i];
            hash[f] = {r,c};
            store[c].insert({r,f});
        }
    }
    
    void changeRating(string food, int nR) {
        string c = hash[food].second;
        int r = hash[food].first;
        hash[food] = {nR,c};
        store[c].erase({r,food});
        store[c].insert({nR,food});
    }
    
    string highestRated(string c) {
        string ans;
        int k = INT_MIN;
        auto it = store[c].rbegin();
        while(it != store[c].rend())
        {
            int b = it->first;
            if(b>=k)
            {
                k = b;
                ans = it->second;
                ++it;
            }
            else break;
        }
        return ans;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */