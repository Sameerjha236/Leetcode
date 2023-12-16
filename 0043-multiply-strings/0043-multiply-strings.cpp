class Solution {
    vector<string> store;
    
    void mul(string &a, char b, string ds)
    {
        int m = a.size();
        int carry = 0;
        for(int i=m-1;i>=0;i--)
        {
            int p = b - '0', q = a[i] - '0';
            int c = p * q + carry;
            char x;
            if(c<=9)
            {
                x = c + '0';
                carry = 0;
            }
            else
            {
                x = c%10 + '0';
                carry = c/10;
            }
            ds += x;
        }
        if(carry) ds += ('0' + carry);
        store.push_back(ds);
    }
public:
    string multiply(string a, string b) {
        if(a == "0" || b == "0") return "0";
        if(a.size()<=b.size()) swap(a,b);
        int n = b.size();
        for(int i=n-1;i>=0;i--)
        {
            string ds;
            for(int j=n-1;j>i;j--) ds +='0';
            mul(a,b[i],ds);
        }

        int m = 0;
        for(auto i: store)
            if(i.size() >=m) m = i.size();
        
        string ans;
        
        int i = 0, carry = 0;
        while(i<m || carry)
        {
            int k = 0;
            for(auto c: store)
            {
                if(c.size()>i) k += (c[i] - '0');
            }
            k += carry;
            char x;
            if(k<=9)
            {
                carry = 0;
                x = '0' + k;
            }
            else
            {
                carry = k / 10;
                x = '0' + (k%10);
            }
            ans += x;
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};