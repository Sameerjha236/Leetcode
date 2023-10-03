//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    static bool comp(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b)
    {
        if(a.first<b.first) return 1;
        return 0;
    }


    vector<int> maxMeetings(int n,vector<int> &s,vector<int> &f){
        vector<pair<int,pair<int,int>>> store;
        for(int i=0;i<n;i++)
        {
            store.push_back( make_pair(f[i], make_pair(s[i],i+1) ) );
        }
        
        sort(store.begin(), store.end(), comp);
        vector<int> ans;
        int prev = 0;
        
        for(auto i:store)
        {
            if(i.second.first > prev)
            {
                ans.push_back(i.second.second);
                prev = i.first;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends