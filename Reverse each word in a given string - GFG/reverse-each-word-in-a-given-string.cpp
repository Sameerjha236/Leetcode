//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        int i=0, n = s.size();
        while(i<n)
        {
            if(s[i] == '.')
            {
                i++;
            }
            else
            {
                int st = i, end = i;
                while(end+1<n && s[end+1] !='.')
                {
                    end++;
                }
                i = end+1;
                while(st<end)
                {
                    swap(s[st], s[end]);
                    st++;
                    end--;
                }
            }
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends