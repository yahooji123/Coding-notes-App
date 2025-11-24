
#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>

/*

Example:
Example 1:
Input: [-1, 2, 3, -4, 5]

Output: (10, -5)

Here, the positive numbers are [2, 3, 5], whose sum is 10.
The negative numbers are [-1, -4], whose sum is -5.
This problem tests your ability to traverse an array and perform conditional aggregation based on the sign of each element.

Example 1:

Input:

Input: arr = [1, 2, 3, -1, -2]

Output:

(6, -3)
Explanation:Sum of positives is 6 and negatives is -3.

Example 2:

Input:

Input: arr = [0, 1, -1]

Output:

(1, -1)
Explanation:Sum of positives is 1 and negatives is -1.

Example 3:

Input:

Input: arr = [-5, -10, -15]

Output:

(0, -30)
Explanation:Sum of positives is 0 and negatives is -30.



*/




class Solution {
public:
  pair<int, int> sumPositiveNegative(const vector<int> &arr) {
    // Implement logic to calculate sums of positive and negative elements
    vector<int> nums = arr;

    int n = nums.size();
    int i = 0;
    int countpositive = 0;
    int countnegative = 0;
    while (i < n) {
      if (nums[i] > 0) {
        countpositive = countpositive + nums[i];
      } else {
        countnegative = countnegative + nums[i];
      }
      i++;
    }
    return {countpositive,countnegative};
  }
};