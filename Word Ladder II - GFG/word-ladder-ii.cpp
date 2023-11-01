//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string begin , string end , vector<string>&word) {
        set<string> st(word.begin(), word.end());
        if(st.find(end) == st.end()) return {{}};
        vector<vector<string>> ans;
        st.erase(begin);
        
        queue<vector<string>> q;
        q.push({begin});
        while(!q.empty())
        {
            int n = q.size();
            set<string> del;
            for(int i=0;i<n;i++)
            {
                vector<string> list = q.front();
                q.pop();
                string curr = list[list.size()-1];
                if(curr == end)
                {
                    ans.push_back(list);
                    continue;
                }
                // cout<<curr<<" -> ";
                for(int j=0;j<curr.size();j++)
                {
                    char t = curr[j];
                    for(char a='a';a<='z';a++)
                    {
                       curr[j] = a;
                       if(st.find(curr) != st.end())
                       {
                        //   cout<<curr<<" ";
                           list.push_back(curr);
                           q.push(list);
                           list.pop_back();
                           del.insert(curr);
                       }
                    }
                    curr[j] = t;
                }
                // cout<<endl;
            }
        
            for(auto k: del)
            {
                // cout<<k<<" ";
                st.erase(k);
            }
            // cout<<endl;
            if(ans.size()) return ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends