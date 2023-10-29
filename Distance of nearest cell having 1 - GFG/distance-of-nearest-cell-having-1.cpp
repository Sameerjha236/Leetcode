//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return grid; // Handle empty grid
    int n = grid[0].size();

    vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    // Find all the non-zero cells and initialize the queue with them
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        for (const auto& dir : dirs) {
            int r = current.first + dir[0];
            int c = current.second + dir[1];

            if (r >= 0 && r < m && c >= 0 && c < n && ans[r][c] == INT_MAX) {
                ans[r][c] = ans[current.first][current.second] + 1;
                q.push({r, c});
            }
        }
    }

    return ans;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends