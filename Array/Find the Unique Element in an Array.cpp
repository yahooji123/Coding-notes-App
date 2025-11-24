
#include<iostream>
#include<vector>
using namespace std;


/*

Example
Input:


nums = [2, 3, 5, 4, 5, 3, 4]
Output:


2
Explanation:

In the given array, every element appears twice except for the number 2. Thus, the output is 2, as it is the unique element.

Your goal is to find this single non-repeating element effectively.

Example 1:

Input:

Input: nums = [2, 3, 5, 3, 2]

Output:

5
Explanation:

Example 2:

Input:

Input: nums = [1, 1, 2, 2, 3]

Output:

3
Explanation:

Example 3:

Input:

Input: nums = [7]

Output:

7
Explanation:

*/



class Solution {
public:
  int findUniqueElement(vector<int> &nums) {
    vector<int> n = nums;
    int count = n.size();
    int ans = 0;
    for (int i = 0; i < count; i++) {
      ans = ans ^ n[i];
    }
    return ans;
  }
};