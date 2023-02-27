/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

bool check(int i, int j, int m, int n, vector<vector<int>> &grid)
{
    bool a = 0, b = 0;
    for (int p = i; p <= m; p++)
    {
        for (int q = j; q <= n; q++)
        {
            if (grid[p][q] == 1)
                a = 1;
            else
                b = 1;
            if (a == 1 && b == 1)
                return false;
        }
    }

    if (a == 1 && b == 1)
        return false;
    return true;
}

Node *solve(vector<vector<int>> &grid, int i, int j, int m, int n)
{
    Node *root=nullptr;
    bool k = check(i, j, m, n, grid);
    if (k == 1)
    {
        root = new Node(grid[i][j], 1);
        return root;
    }
    Node *a=nullptr, *b=nullptr, *c=nullptr, *d=nullptr;
    int p=(i+m)/2,q=(j+n)/2;
    a = solve(grid,i,j,p,q);

    b = solve(grid,i,q+1,p,n); 

    c = solve(grid,p+1,j,m,q); 
    
    d = solve(grid,p+1,q+1,m,n); 

    root = new Node(grid[i][j], 0, a, b, c, d);

    return root;
}

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        return solve(grid, 0, 0, n-1, n-1);
    }
};