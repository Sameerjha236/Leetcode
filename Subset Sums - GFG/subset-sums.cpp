//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void solve(vector<int> &arr, int n, int i,int curr, vector<int> &ans)
    {
        if(i==n) 
        {
            ans.push_back(curr);
            return;
        }
        solve(arr,n,i+1,curr+arr[i],ans);
        solve(arr,n,i+1,curr,ans);
    }

    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
       vector<int> ans;
       int curr=0;
       solve(arr,n,0,curr,ans);
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends