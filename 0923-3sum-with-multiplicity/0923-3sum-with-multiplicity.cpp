class Solution {
public:

long long int comb(int N, int r)
{
    long long int res = 0,mod = 1e9 + 7;
    if (r == 0) {
        return 1;
    }
    else {
        res = comb(N, r - 1)
              * (N - r + 1) / r;
    }
    res = res % mod;
    return res;
}

    int threeSumMulti(vector<int>& arr, int target) {
        long long int ans = 0,n=arr.size(),mod = 1e9 + 7;
        unordered_map<int,int> store;
        for(auto i:arr) store[i]++;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && arr[i] == arr[i-1]) continue;
            int left = target - arr[i];
            int lo = i+1,hi = n-1;
            while(lo<hi)
            {
                int k = arr[lo] + arr[hi];
                if(k == left)
                {
                    int a = arr[i], b=arr[lo], c=arr[hi];
                    long long int curr=0;
                    if(a == b && b == c)
                    {
                        curr = comb(store[a],3);
                    }
                    else if(a == b)
                    {
                        curr = comb(store[a],2) * comb(store[c],1);
                    }
                    else if(b==c)
                    {
                        curr =  comb(store[c],2) * comb(store[a],1);

                    }
                    else if(a==c)
                    {
                        curr = comb(store[a],2) * comb(store[b],1);
                    }
                    else
                    {
                        curr = comb(store[a],1)*comb(store[b],1)*comb(store[c],1);
                    }
                    curr = curr % mod;
                    ans +=curr;
                    ans = ans % mod;
                    while(lo<hi && arr[lo]==arr[lo+1]) lo++;
                    while((lo<hi && arr[hi]==arr[hi-1])) hi--;
                    lo++;
                    hi--;
                }
                else if(k>left) hi--;
                else lo++;
            }
        }
        return ans;
    }
};