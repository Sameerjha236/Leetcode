class Solution {
public:
     bool fun(vector<int>& nums,int sum,int ind,int n,vector<vector<int>>& res){
        if(res[ind][sum]!=-1) return res[ind][sum];
         if(sum==0) return true;
        if(ind==n) return false;
        bool val=false;
        if(sum>=nums[ind])
            val=fun(nums,sum-nums[ind],ind+1,n,res);
        bool val2=fun(nums,sum,ind+1,n,res);
        return res[ind][sum]=val|val2;
        
    }
    
    
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto x:nums) sum+=x;
        if(sum&1) return false;
        vector<vector<int>> res(n+1,vector<int> (sum+1,-1));
        return fun(nums,sum/2,0,n,res);
    }
};