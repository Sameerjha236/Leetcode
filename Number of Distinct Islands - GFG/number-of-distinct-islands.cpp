//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int cord[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
    
    void dfs(int i, int j,int p, int q, vector<vector<int>> &ds, vector<vector<int>> &grid)
    {
        ds.push_back({p,q});
        grid[i][j] = 0;
        for(auto k: cord)
        {
            int x = i + k[0];
            int y = j + k[1];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y] == 1)
            {
                dfs(x,y,p+k[0],q+k[1],ds,grid);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m =grid[0].size();
        map<vector<vector<int>>,int> hash;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0) continue;
                vector<vector<int>> ds;
                
                dfs(i,j,0,0,ds,grid);
                hash[ds]++;
            }
        }
        return hash.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends