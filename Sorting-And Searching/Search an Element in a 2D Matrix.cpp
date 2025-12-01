#include<iostream>
#include<vector>
using namespace std;



/*

Example:
Input:


matrix = [[1, 4, 7, 11, 15],
          [2, 5, 8, 12, 19],
          [3, 6, 9, 16, 22],
          [10, 13, 14, 17, 24],
          [18, 21, 23, 26, 30]]
target = 5
Output: true

Explanation: 5 is located in the second row of the matrix.

Input:


matrix = [[1, 4, 7, 11, 15],
          [2, 5, 8, 12, 19],
          [3, 6, 9, 16, 22],
          [10, 13, 14, 17, 24],
          [18, 21, 23, 26, 30]]
target = 20
Output: false

Explanation: 20 does not exist in the matrix.

Example 1:

Input:

Input: matrix = [[1, 3, 5], [7, 9, 11], [13, 15, 17]], target = 9

Output:

true
Explanation:

Example 2:

Input:

Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], target = 10

Output:

false
Explanation:

Example 3:

Input:

Input: matrix = [[10, 20, 30], [40, 50, 60], [70, 80, 90]], target = 80

Output:

true
Explanation:

*/


class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    // Implement the solution here
    int row = matrix.size();
    int cols = matrix[0].size();
    int total = row * cols;
    int s = 0;
    int e = total - 1;

    while (s <= e) {
      int mid = (s + e) / 2;

      // convert mid into rowIndex, colIndex
      int rowIndex = mid / cols;
      int colIndex = mid % cols;

      if (matrix[rowIndex][colIndex] == target) {
        return true;
      }
      if (target > matrix[rowIndex][colIndex]) {
        s = mid + 1;

      } else {
        e = mid - 1;
      }
    }
    return false;
  }
};