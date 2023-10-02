class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        int a=0,b=0,n=colors.length();
        for(int i=1;i<n;i++)
        {
            if(colors[i]=='A' && colors[i+1]=='A' && colors[i-1]=='A')
            {
                a++;
            }
            if(colors[i]=='B' && colors[i+1]=='B' && colors[i-1]=='B')
            {
                b++;
            }
        }
        return (a>b && a!=0)?1:0;
    }
};