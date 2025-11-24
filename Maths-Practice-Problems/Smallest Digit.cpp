


/*

Example
Input: num = 5892
Output: 2
Explanation: Digits in 5892 are 5, 8, 9, and 2. The smallest digit among these is 2.

Input: num = 4356
Output: 3
Explanation: The digits present in 4356 are 4, 3, 5, and 6. The smallest digit is 3.

Input: num = 1005
Output: 0 Explanation: Digits in 1005 are 1, 0, 0, and 5. Here, 0 is the smallest digit.

The function should work efficiently within the defined constraints.

Example 1:

Input:

Input: num = 123

Output:

1
Explanation:Smallest digit in 123 is 1.

Example 2:

Input:

Input: num = 456

Output:

4
Explanation:Smallest digit in 456 is 4.

Example 3:

Input:

Input: num = 78910

Output:

0
Explanation:Smallest digit in 78910 is 0.

*/

class Solution {
public:
  int smallestDigit(int num) {
    // Implement logic to find the smallest digit
    int smallest = 9;
    if (num == 0)
      return 0;

    while (num != 0) {
      int digit = num % 10;
      if (digit < smallest) {
        smallest = digit;
      }
      num = num / 10;
    }
    return smallest;
  }
};