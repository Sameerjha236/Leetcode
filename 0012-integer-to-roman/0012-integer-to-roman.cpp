class Solution {
public:

    string solve(int k, char o, char f, char t)
    {
        string curr;
        if(k == 9)
            curr  = curr + o + t;
        else if(k>4)
        {
            curr  = curr + f;
            k-=5;
            while(k--) {
                curr  = curr + o; 
            }

        }
        else if (k==4)
            curr  = curr +  o +f;
        else
        {
            while(k--) {
                curr= curr +  o;
            }
        }
        return curr;
    }

    string intToRoman(int num) {
        string ans;
        for(int i=0;num;i++)
        {
            int k = num%10;
            num = num/10;
            string curr;
            if(i==0)
                curr = solve(k,'I','V','X');
            else if(i==1)
                curr = solve(k,'X','L','C');
            else if(i==2)
                curr = solve(k,'C','D','M');

            else if(i==3)
                curr = solve(k,'M','M','M');
            ans.insert(0,curr);
        }
        
        return ans;
    }
};