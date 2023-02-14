class Solution {
public:
   string addBinary(string p, string q)

{

    string r;

    char a='0',b='0',c='0';

    int n=max(p.size(),q.size());

    for(int i=0;i<n || c!='0';i++)

    {

        a=b='0';

        if(i<p.size())

        {

            a=p[p.size()-1-i];

        }

        if(i<q.size())

        {

            b=q[q.size()-1-i];

        }

        int m=a+b+c;

        if(m==144)

        {

            c='0';

            r+='0';

        }

        else if(m==147)

        {

            c='1';

            r+='1';

        }

        else if(m==145)

        {

            c='0';

            r+='1';

        }

        else if(m==146)

        {

            c='1';

            r+='0';

        }

    }

    reverse(r.begin(),r.end());

    return r;

}
        

};