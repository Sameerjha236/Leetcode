class Solution {
public:
    vector <string> result;
    vector<string> simplifiedFractions(int n) {
        if (n == 1){
            return result;
        } 
        else if (n==2)
        {
            result.push_back("1/2");
            return simplifiedFractions(1);
        }
        else{
            for (int i = 1; i < n; i ++)
            {
                if ( __gcd(i, n) == 1)
                {
                    result.push_back(to_string(i)+ "/" + to_string(n));
                }
            }
            return simplifiedFractions(n-1);
        }
    }
};