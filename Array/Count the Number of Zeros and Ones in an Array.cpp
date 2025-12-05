#include<iostream>
#include<vector>
using namespace std;

/*

Example 1:

Input:

Input: nums = [0, 1, 0, 1, 1, 0]

Output:

zeros: 3, ones: 3
Explanation:Equal number of zeros and ones, count of each is 3.

Example 2:

Input:

Input: nums = [1, 1, 1, 1, 1]

Output:

zeros: 0, ones: 5
Explanation:All elements are ones, so zero count is 0 and one count is 5.

Example 3:

Input:

Input: nums = [0, 0, 0, 0, 0, 0]

Output:

zeros: 6, ones: 0
Explanation:All elements are zeros, so zero count is 6 and one count is 0.

*/



class Solution {
public:
  std::pair<int, int> countZerosAndOnes(const std::vector<int> &nums) {
    // Implement this method
    int totalOnes = 0;
    int totalZeros = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] == 0) {
        totalZeros++;
      }
      if (nums[i] == 1) {
        totalOnes++;
      }
    }
    // return {totalZeros, totalOnes};
    pair<int, int> ans;
    ans.first = totalZeros;
    ans.second = totalOnes;
    return ans;
  }
};