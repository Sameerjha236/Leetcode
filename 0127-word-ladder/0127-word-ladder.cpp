class Solution {

bool check(string a, string b)
{
    bool c = 0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i] != b[i])
        {
            if(c == 0) c=1;
            else return 0;
        } 
    }
    return 1;
}

public:
    int ladderLength(string begin, string end, vector<string>& words) {
        int n = words.size();
        if(n == 1)
        {
            if(end == words[0] && check(begin,end)) return 2;
            return 0;
        }
        map<string, vector<string>> adj;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(check(words[i], words[j]))
                {
                    adj[words[i]].push_back(words[j]);
                    adj[words[j]].push_back(words[i]);
                }    
            }
        }
        queue<string> q;
        map<string,int> dist;
        for(auto k: adj)
        {
            if(check(k.first,begin))
            {
                if(k.first == end) return 2;
                q.push(k.first);
                dist[k.first] = 1;
            }
            else dist[k.first] = INT_MAX;
        }
        while(!q.empty())
        {
            string node = q.front();
            // cout<<node<<" -> ";
            q.pop();
            for(auto k:adj[node])
            {
                if(dist[node] + 1 < dist[k])
                {
                    dist[k] = dist[node] + 1;
                    // cout<<k<<" ";
                    if(k == end) break;
                    q.push(k);
                }
            }
                // cout<<endl;
        }
        if(dist[end] == INT_MAX) return 0;
        if(dist[end] == 0) return 0;
        return dist[end]+1;
    }
};