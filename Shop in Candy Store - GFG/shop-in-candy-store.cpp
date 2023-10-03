//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int vec[], int n, int k)
    {
        if(k == 0)
        {
            int s = 0;
            for(int i =0;i<n;i++) s += vec[i];
            return {s,s};
        }
        sort(vec,vec+n);
        int l=0, r = n, mN=0,mX=0;
        
        while(l<r)
        {
            mN += vec[l];
            // cout<<l<<" - "<<r<<endl;
            r -=k;
            l++;
        }
        
        l=-1;
        r=n-1;
        while(l<r)
        {
            mX += vec[r];
            l += k;
            r--;
        }
        return {mN,mX};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends