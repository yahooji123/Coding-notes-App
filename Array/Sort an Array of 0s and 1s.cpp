

/*

Example
Example 1:
Input:

n = 6
arr = [0, 1, 0, 1, 0, 1]

Output:

[0, 0, 0, 1, 1, 1]

Explanation: The input array [0, 1, 0, 1, 0, 1] is rearranged such that all 0s appear before all 1s, resulting in the array [0, 0, 0, 1, 1, 1].

Instructions
Implement a function that takes an integer array containing only 0s and 1s, and returns a new sorted array where all 0s appear before all 1s.
The function should operate in linear time, making it suitable for handling very large arrays.
Example 1:

Input:

Input: nums = [0, 1, 0, 1, 0, 1]

Output:

[0, 0, 0, 1, 1, 1]
Explanation:

Example 2:

Input:

Input: nums = [1, 1, 1, 0, 0, 0]

Output:

[0, 0, 0, 1, 1, 1]
Explanation:

Example 3:

Input:

Input: nums = [0, 0, 0, 0, 0]

Output:

[0, 0, 0, 0, 0]
Explanation:

*/




#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int totalzero = 0;
    int totalones = 0;
    vector<int> copy = nums;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        totalzero++;
      } else {
        totalones++;
      }
    }
    fill(copy.begin(), copy.begin() + totalzero, 0);
    fill(copy.begin() + totalzero, copy.end(), 1);


    return copy; 
  }
};
