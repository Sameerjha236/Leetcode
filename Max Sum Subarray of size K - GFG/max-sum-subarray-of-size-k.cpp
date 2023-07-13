//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &num , int n){
        // code here 
        long i=0,j=0,ans=0,curr=0;
        while(j<n)
        {
            if(j-i+1<=k)
            {
                curr +=num[j];
                
                j++;
            }
            else
            {
                curr -= num[i];
                curr += num[j];
                i++;
                
                j++;
            }
            ans = max(curr,ans);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends