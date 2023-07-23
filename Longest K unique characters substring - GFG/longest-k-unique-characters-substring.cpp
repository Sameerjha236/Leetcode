//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0,j=0,n=s.size(),ans=-1;
        unordered_map<char,int> hash; // char freq
        // dxfircvs
        // 2
        while(j<n)
        {
            char c = s[j];
            // cout<<i<<" "<<j<<" -> ";
            hash[c]++;
            if(hash.size()==k)
            {
                ans = max(ans,j-i+1);
                // cout<<"size\n";
                j++;
            }
            else if(hash.size()<k)
            {
                // cout<<"small\n";
                j++;
            }
            else
            {
                // cout<<"big\n";
                while(hash.size()>k)
                {
                    int v = hash[s[i]];
                    if(v>1)
                    {
                        hash[s[i]] = v-1;  
                        // cout<<s[i]<<" dec\n";
                    }
                    else
                    {
                        hash.erase(s[i]);
                        // cout<<s[i]<<" rem\n";
                    }
                    i++;
                }
                if(hash.size()==k) ans = max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends