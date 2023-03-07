
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m - 1, k = 0;
        if (m != 1)
        {
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (matrix[mid][0] == target)
                    return 1;
                else if (matrix[mid][0] > target)
                    r = mid - 1;
                else
                {
                    k = mid;
                    l = mid + 1;
                }
            }
        }

        l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (matrix[k][mid] == target)
                return 1;
            else if (matrix[k][mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return 0;
    }
};