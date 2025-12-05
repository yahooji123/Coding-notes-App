#include <iostream>
#include <vector>
using namespace std;

/*       Row with Maximum 1’s

Example
Input:
mat = [[0, 0, 0, 1], [0, 0, 1, 1], [0, 1, 1, 1], [1, 1, 1, 1]]

Output:
3

Explanation:
All the rows are:

Row 0: 1 one
Row 1: 2 ones
Row 2: 3 ones
Row 3: 4 ones
Since row 3 contains the maximum number of 1s, the index 3 is returned.

Note:
If no row contains a 1 at all, return -1.

Example 1:

Input:

m = 4, n = 4, matrix = [[0,0,0,1],[0,0,1,1],[0,1,1,1],[1,1,1,1]]

Output:

3
Explanation:Row'3 contains 4 ones, the maximum among all rows.

Example 2:

Input:

m = 3, n = 5, matrix = [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]

Output:

-1
Explanation:No row contains a 1, so −1 is returned.

Example 3:

Input:

m = 4, n = 4, matrix = [[0,1,1,1],[0,1,1,1],[0,0,1,1],[0,0,1,1]]

Output:

0
Explanation:Rows 0 and 1 each have two 1 s, rows 2 and 3 each have three 1 s; the first of the rows with the highest count (index2) is returned.


*/

int rowWithMaxOnes(const vector<vector<int>> &mat)
{
    // Implement the function to find the row with the maximum number of 1s.
    // Return the index of the row.
    int n = mat.size();
    int m = mat[0].size();

    int maxCnt = 0;
    int maxIdx = -1;

    for (int i = 0; i < n; i++)
    {
        // will find no. of ones in ith row

        auto it = lower_bound(mat[i].begin(), mat[i].end(), 1);

        int firstOneTdx = it - mat[i].begin();

        int ones = m - firstOneTdx;

        if (ones > maxCnt)
        {
            maxCnt = ones;
            maxIdx = i;
        }
    }

    return maxIdx;
}