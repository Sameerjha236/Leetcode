//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> dest) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,int>> cord = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>> dist(m, vector<int> (n,INT_MAX));
        queue<pair<int, pair<int,int>>> q;
        
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        
        while(!q.empty())
        {
            int cost = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            if(x == dest.first && y == dest.second) return cost;
            
            for(auto k: cord)
            {
                int a = x + k.first;
                int b = y + k.second;
                
                if(a>=0 && b>=0 && a<m && b<n && grid[a][b] && dist[a][b] > cost + 1)
                {
                    dist[a][b] = cost + 1;
                    q.push({cost+1, {a,b}});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends