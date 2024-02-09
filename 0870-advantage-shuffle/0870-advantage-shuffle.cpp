class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        int n = nums2.size();
        for(int i=0;i<n;i++)
            pq.push(make_pair(nums2[i],i));

        vector<int> ans(n,0);
        int a = 0;
        while(!pq.empty() && a<n)
        {
            int k = pq.top().first, i = pq.top().second;
            while(a<n && nums1[a]<=k) a++;
            if(a == n) break;
            ans[i] = nums1[a];
            nums1[a] = -1;
            a++; 
            pq.pop();
        }
        a = 0;
        while(!pq.empty())
        {
            int i = pq.top().second;
            pq.pop();
            while(nums1[a] == -1) a++;
            ans[i] = nums1[a];
            a++;
        }
        return ans;
    }
};