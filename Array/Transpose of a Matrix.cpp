#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*

Example
Input:

2 3
1 2 3
4 5 6
Output:

1 4
2 5
3 6
Explanation:
The given matrix A:


A = [
  [1, 2, 3],
  [4, 5, 6]
]
The transpose of the matrix A, denoted by A^T, becomes:


A^T = [
  [1, 4],
  [2, 5],
  [3, 6]
]
Notice how element A[i][j] in the original matrix becomes A[j][i] in the transposed matrix. You need to construct and return this transposed matrix as the result.

Example 1:

Input:

Input: n = 1, m = 1, matrix = [[5]]

Output:

5
Explanation:A 1x1 matrix remains the same after transposition.

Example 2:

Input:

Input: n = 2, m = 2, matrix = [[1, 2], [3, 4]]

Output:

1 3
2 4
Explanation:Transposing a 2x2 matrix swaps rows and columns.

Example 3:

Input:

Input: n = 2, m = 3, matrix = [[1, 2, 3], [4, 5, 6]]

Output:

1 4
2 5
3 6
Explanation:Transposing a 2x3 matrix results in a 3x2 matrix.

*/

class Matrix
{
public:
    vector<vector<int>> transpose(const vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return {};
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> transposed(m, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }
};