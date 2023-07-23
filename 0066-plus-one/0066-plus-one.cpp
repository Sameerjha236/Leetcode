class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            int k = digits[i] + c;
            if(k>=10)
            {
                k -=10;
                c=1;
            }
            else c=0;
            digits[i] = k;
            if(!c) break;
        }
        if(c)
        {
            vector<int> ans;
            ans.push_back(1);
            for(int i=0;i<digits.size();i++)
            {
                ans.push_back(digits[i]);
            }
            return ans;
        }
        return digits;
    }
};