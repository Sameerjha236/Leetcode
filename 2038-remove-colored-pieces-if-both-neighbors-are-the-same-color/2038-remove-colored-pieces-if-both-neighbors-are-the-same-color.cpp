class Solution {
public:
    bool winnerOfGame(string colors) {
        map<char, int> c;
        for (int i = 0; i < colors.size(); ) 
        {
            char x = colors[i];
            int j = i;
            while (j < colors.size() && colors[j] == x) 
            {
                j++;
            }
            c[x] += max(j - i - 2, 0);
            i = j;
        }

        if (c['A'] > c['B']) {
            return true;
        }
        return false;
    }
};
