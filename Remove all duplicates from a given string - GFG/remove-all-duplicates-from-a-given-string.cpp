//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    vector<bool> visSm(26,1);
	    vector<bool> visLg(26,1);
	    string ans;
	    for(int i=0;i<str.size();i++)
	    {
	        char c = str[i];
	        if(c>='a' && c<='z' && visSm[c-'a'])
	        {
	                ans += c;
	                visSm[c-'a'] = 0;
	        }
	        else if(c>='A' && c<='Z' && visLg[c-'A'])
	        {
	                ans += c;
	                visLg[c-'A'] = 0;
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
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends