class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans;

    int left = 0;
    int top = 0;
    int right = n - 1;
    int bottom = m - 1;
    int dir = 1;

    while (left <= right and top <= bottom)
    {
        if (dir == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[left][i]);
            }
            left++;
            dir = 2;
        }

        if (dir == 2)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[i][bottom]);
            }
            bottom--;
            dir = 3;
        }

        if (dir == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[right][i]);
            }
            right--;
            dir = 4;
        }

        if (dir == 4)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[i][top]);
            }
            top++;
            dir = 1;
        }
    }
    vector<int> res;
    for (int i = 0; i < m * n; i++)
    {
        res.push_back(ans[i]);
    }
    return res;
}
};