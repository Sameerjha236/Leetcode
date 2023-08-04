class Solution {
public:

    int checkVowel(char m)
    {
        if(m == 'a') return 1;
        if(m == 'e') return 2;
        if(m == 'i') return 3;
        if(m == 'o') return 4;
        if(m == 'u') return 5;
        return 0;
    }

    int longestBeautifulSubstring(string word) {
       int ans = 0,n=word.size(),i=0,j=0,pre=-1;
        while(j<n)
        {
            char curr = word[j];
            int check = checkVowel(curr);
            if(curr == 'a')
            {
                if(pre == -1)
                {
                    i=j;
                    pre = 1;
                    j++;
                }
                else if(pre == 1)
                {
                    j++;
                }
                else
                {
                    i = j;
                    pre =1;
                    j++;
                }
            }
            else if(check == pre + 1 || check == pre)
            {
                pre = check;
                if(check == 5)
                    ans = max(ans,j-i+1);
                j++;
            }
            else
            {
                pre = -1;
                j++;
            }
        }
       return ans; 
    }
};