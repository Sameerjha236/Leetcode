static int ind;
static bool comp(vector<int> &a, vector<int> &b)
{
    if(a[ind]>=b[ind]) return 1;
    return 0;
}
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        ind = k;
        sort(score.begin(),score.end(),comp);
        return score;
    }
};