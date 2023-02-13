class Solution {
public:
    int countOdds(int low, int high)
{
    if ((low & 1) == 1 && (high & 1) == 1)
    {
        if(low == high)
            return 1;
        return ((high - low - 1) / 2 + 2);
    }
    if (((low & 1) == 0 && (high & 1) == 1) || ((low & 1) == 1 && (high & 1) == 0))
    {
        return ((high - low) / 2 + 1);
    }
    else
    {
        return (high - low) / 2;
    }
}
};