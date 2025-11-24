#include <limits.h>




/*

Example
Example 1:

Input:


arr = [1, 2, 3, 4, 5]
Output:


5
Explanation: The largest number in the array [1, 2, 3, 4, 5] is 5.

Example 2:

Input:


arr = [-1, -2, -3, -4, -5]
Output:


-1
Explanation: Even though all numbers are negative, -1 is the highest value in the array.

Approach
While handling the problem, ensure you iterate through the array and keep track of the current maximum element. It is necessary to update this maximum as you progress through the array.

Example 1:

Input:

Input: arr = [1, 2, 3, 4, 5]

Output:

5
Explanation:The maximum element in the array is 5.

Example 2:

Input:

Input: arr = [5, 4, 3, 2, 1]

Output:

5
Explanation:The maximum element is at the beginning.

Example 3:

Input:

Input: arr = [10, 20, 5, 40, 30, 50]

Output:

50
Explanation:The maximum element is 50, appearing last.

*/





class Solution {
public:
  int findMaximum(vector<int> &arr) {
    // Your code here
    int size = arr.size();
    int maximum = INT_MIN;
    for (int i = 0; i < size; i++) {
      maximum = max(maximum, arr[i]);
    }
    return maximum;
  }
};