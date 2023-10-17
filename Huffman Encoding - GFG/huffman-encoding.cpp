//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct TreeNode 
{
    pair<int,char> data;
    TreeNode *left, * right;
    TreeNode(pair<int,char> a)
    {
        data = a;
        left = right = nullptr;
    }
    
    TreeNode(pair<int,char> a, TreeNode * x, TreeNode *y)
    {
        data = a;
        left = x;
        right = y;
    }
};

class Solution
{
public:

    void preOrder(TreeNode * head, string curr, vector<string> &ans)
    {
        if(!head->left && !head->right)
        {
            ans.push_back(curr);
            return;
        }
        if(head->left)
        {
            curr.push_back('0');
            preOrder(head->left,curr,ans);
            curr.pop_back();
        }
        
        if(head->right)
        {
            curr.push_back('1');
            preOrder(head->right,curr,ans);
        }
    }

    static bool comp(TreeNode *a, TreeNode *b)
    {
        return a->data.first > b->data.first; // Use > for a min-heap
    }

    vector<string> huffmanCodes(string s, vector<int> f, int n)
    {
        priority_queue<TreeNode *, vector<TreeNode *>, decltype(&comp)> pq(comp);
        
        for(int i = 0; i < n; i++)
        {
            TreeNode *curr = new TreeNode(make_pair(f[i], s[i]));
            pq.push(curr);
        }
        
        while(pq.size()>1)
        {
            int a = pq.top()->data.first;
            TreeNode * l = pq.top();
            pq.pop();
            int b = pq.top()->data.first;
            TreeNode * r = pq.top();
            pq.pop();
            TreeNode * curr = new TreeNode(make_pair(a+b,'!'),l,r);
            pq.push(curr);
        }
        TreeNode * head = pq.top();
        string curr;
        vector<string> ans;
        preOrder(head,curr,ans);
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends