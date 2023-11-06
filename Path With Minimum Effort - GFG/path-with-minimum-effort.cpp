//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<pair<int,int>> cord = {{0,1},{0,-1}, {1,0}, {-1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >q;
        vector<vector<int>> dist(m, vector<int> (n,INT_MAX));
        
        dist[0][0] = 0;
        q.push({0, {0,0}});
        
        while(!q.empty())
        {
            int cost = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            if(r == m-1 && c == n-1) return cost;
            q.pop();
            
            for(auto k: cord)
            {
                int x = r + k.first;
                int y = c + k.second;
                
                if(x>=0 && y>=0 && x<m && y<n)
                {
                    int val = abs(grid[x][y] - grid[r][c]);
                    val = max(val, cost);
                    
                    if(val < dist[x][y])
                    {
                        dist[x][y] = val;
                        q.push({val, {x,y}});
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends