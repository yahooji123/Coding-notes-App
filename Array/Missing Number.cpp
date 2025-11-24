
#include<iostream>
#include<vector>
using namespace std;

/*

Note:
Try to implement an algorithm with a linear runtime complexity.

Example 1:

Input:

n=3 nums=[3,0,1]

Output:

2
Explanation:The range should contain {0,1,2,3}. Only 2 is absent.

Example 2:

Input:

n=4 nums=[1,2,3,4]

Output:

0
Explanation:Numbers present are {1,2,3,4}; 0 is missing.

Example 3:

Input:

n=4 nums=[0,1,2,3]

Output:

4
Explanation:Expected range is {0,1,2,3,4}; 4 is not present.


*/


class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int total = n * (n + 1) / 2;
    int sum = 0;

    for (int i = 0; i < n; i++) {
      sum += nums[i];
    }

    return total - sum;
  }
};
