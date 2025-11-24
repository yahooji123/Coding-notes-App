



/*

Examples
Example 1:
Input:


num = 12345
Output:


15
Explanation:

The individual digits of the number 12345 are 1, 2, 3, 4, and 5. Their sum is 1 + 2 + 3 + 4 + 5 = 15.

Example 2:
Input:


num = 0
Output:


0
Explanation:

The only digit here is 0, so the sum is 0.

Example 1:

Input:

Input: num = 123

Output:

6
Explanation:Sum of 1, 2, and 3 is 6.

Example 2:

Input:

Input: num = 456

Output:

15
Explanation:Sum of 4, 5, and 6 is 15.

Example 3:

Input:

Input: num = 0

Output:

0
Explanation:Sum of digits in 0 is 0.

*/


class Solution {
public:
  int sumOfDigits(int num) {
    // Implement logic to calculate the sum of digits
    int sum = 0;
    while (num != 0) {
      sum = sum + num % 10;
      num = num / 10;
    }
    return sum;
  }
};