#include<iostream>
#include<vector>
using namespace std;

/*

Your Task:
Write a function to return the index of the pivot.

Example:
Input: nums = [4, 5, 6, 7, 0, 1, 2]

Output: 3

Explanation: In this array, the pivot point is the index 3 because the array [4, 5, 6, 7], when combined with [0, 1, 2], forms the original sorted array [0, 1, 2, 4, 5, 6, 7].

Example 1:

Input:

Input: nums = [3, 4, 5, 1, 2]

Output:

2
Explanation:

Example 2:

Input:

Input: nums = [4, 5, 6, 7, 0, 1, 2]

Output:

3
Explanation:

Example 3:

Input:

Input: nums = [1, 2, 3, 4, 5]

Output:

-1
Explanation:

*/


class Solution {
public:
  int findPivotIndex(vector<int> &nums) {

    int n = nums.size();
    int s = 0;
    int e = n - 1;

    while (s <= e) {

      int mid = (s + e) / 2;

      // Case 1: mid is pivot
      if (mid + 1 < n && nums[mid] > nums[mid + 1]) {
        return mid;
      }

      // Case 2: mid is in rotated part (line-2)
      if (nums[mid] < nums[s]) {
        e = mid - 1;     // go left
      }

      else {
        s = mid + 1;     // go right
      }
    }

    // no pivot means array is not rotated
    return -1;
  }
};
