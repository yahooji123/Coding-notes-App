

/*

Example:
Input:

nums = [4, 2, 7, 1, 9, 3]
target = 7

Output:

2

Explanation: The target 7 is located at index 2 in the array.

Input:

nums = [5, 8, 6, 3]
target = 2

Output:

-1

Explanation: The target 2 is not present in the array, hence the output is -1.

Example 1:

Input:

Input: nums = [1, 2, 3, 4, 5], target = 3

Output:

2
Explanation:Element 3 is found at index 2.

Example 2:

Input:

Input: nums = [10, 20, 30, 40, 50], target = 50

Output:

4
Explanation:Element 50 is found at index 4.

Example 3:

Input:

Input: nums = [7, 8, 9, 10, 11], target = 5

Output:

-1
Explanation:Element 5 is not present in the array.

*/

int searchElementInArray(vector<int> &nums, int target) {
  // Implement the logic to search for an element in the array
  // Placeholder return

  int size = nums.size();

  for (int i = 0; i < size; i++) {
    int value = nums[i];
    if (value == target) {
      return i;
    }
  }
  return -1;
}
