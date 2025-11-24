



/*

Example
Example 1:
Input:

nums = [1, 2, 3, 4, 5, 6, 7], k = 3

Output:

[5, 6, 7, 1, 2, 3, 4]

Explanation:

Rotating the array to the right by 3 steps produces the array [5, 6, 7, 1, 2, 3, 4]. Elements are moved to the right, and the trailing elements are repositioned at the beginning of the array.
Example 2:
Input:

nums = [-1, -100, 3, 99], k = 2

Output:

[3, 99, -1, -100]

Explanation:

Rotating the array to the right by 2 steps results in [3, 99, -1, -100]. The elements at the end wrap around to the start of the array.
Note
The number of rotations exceeds the array length in some cases. Take into consideration that rotating the array n times results in the same arrangement as rotating it n % length of array times, thus simplifying the problem.
Example 1:

Input:

Input: nums = [1, 2, 3, 4, 5, 6, 7], k = 3

Output:

[5, 6, 7, 1, 2, 3, 4]
Explanation:

Example 2:

Input:

Input: nums = [-1, -100, 3, 99], k = 2

Output:

[3, 99, -1, -100]
Explanation:

Example 3:

Input:

Input: nums = [1, 2, 3, 4, 5], k = 1

Output:

[5, 1, 2, 3, 4]
Explanation:

*/

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    // step1- temp me array ko store kr lo

    int n = nums.size();
    k = k % n;
    vector<int> temp;
    for (int i = n - k; i <= n - 1; i++) {
      int value = nums[i];
      temp.push_back(value);
    }
    // step 2 me shift loop
    for (int i = n - 1; i >= 0; i--) {
      if (i - k >= 0) {
        nums[i] = nums[i - k];
      }
    }
    // step 3 me copy form temp array
    for (int i = 0; i < k; i++) {
      nums[i] = temp[i];
    }
  }
};