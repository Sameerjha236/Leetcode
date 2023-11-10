//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(1e5, 1e9);
        int mod = 1e5;
        dist[start] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,start});
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            if(node == end) return dis;
            pq.pop();
            
            for(auto k:arr)
            {
                int val = (k * node) ;
                val = val % mod;
                if(dist[val] > dis + 1)
                {
                    dist[val] = dis + 1;
                    pq.push({dist[val], val});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends