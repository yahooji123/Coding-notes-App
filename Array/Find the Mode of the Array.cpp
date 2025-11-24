
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


/*

Example
Example 1:
Input: [3, 3, 2, 1, 5, 1]
Output: 1
Explanation: The numbers 3 and 1 both appear twice, but 1 is smaller than 3, so 1 is the mode.

Example 2:
Input: [7, 7, 7, 7, 8, 8]
Output: 7
Explanation: The number 7 appears four times while 8 appears twice, making 7 the mode.

Example 3:
Input: [-1, -1, -2, -2, -3]
Output: -2
Explanation: The numbers -1 and -2 both appear twice, but -2 is smaller than -1, so -2 is the mode.

Example 1:

Input:

Input: arr = [1, 2, 2, 3, 3, 3]

Output:

3
Explanation:3 is the mode with the highest frequency.

Example 2:

Input:

Input: arr = [4, 5, 5, 6, 6]

Output:

5
Explanation:5 and 6 have the same frequency, but 5 is smaller.

Example 3:

Input:

Input: arr = [10, 10, 10, 20, 20]

Output:

10
Explanation:10 is the mode with the highest frequency.

*/




class Solution {
public:
  int findMode(const vector<int> &arr) {
    // Implement logic to find mode
    vector<int> v = arr;
    sort(v.begin(), v.end());
    int maxfreq = 1;
    int mode = v[0];
    int cf = 1;
    int n = v.size();
    for (int i = 1; i < n; i++) {
      if (v[i] == v[i - 1]) {
        cf++;
      } else
        cf = 1;
      if (cf > maxfreq) {
        // i got new winner
        maxfreq = cf;
        mode = v[i];
      }
    }
    return mode;
  }
};