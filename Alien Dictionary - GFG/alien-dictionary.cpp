//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        string ans;
        vector<pair<char,char>> edge;
        for(int i=0;i<n-1;i++)
        {
            string temp = dict[i];
            string curr = dict[i+1];
            int l = min(temp.size(),curr.size());
            for(int j=0;j<l;j++)
            {
                if(temp[j] == curr[j]) continue;
                edge.push_back(make_pair(temp[j],curr[j]));
                break;
            }
        }
        
        map<char,set<char>> adj;
        
        for(auto i:edge)
        {
            adj[i.first].insert(i.second);
        }
        
        vector<int> deg(k,0);
        for(auto i:adj)
        {
            for(auto j:i.second)
                deg[j-'a']++;
        }
        
        queue<char> store;
        
        for(int i=0;i<k;i++)
            if(deg[i] == 0) store.push('a' + i);
        while(!store.empty())
        {
            char node = store.front();
            store.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                deg[it-'a']--;
                if(deg[it-'a'] == 0) store.push(it);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends