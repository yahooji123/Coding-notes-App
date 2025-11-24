

/*

Example:
Input:


num = 12
Output:


6
Explanation: Divisors of 12 are 1, 2, 3, 4, 6, and 12. Hence, the number of divisors is 6.

Example 1:

Input:

Input: num = 1

Output:

1
Explanation:1 has only one divisor: itself.

Example 2:

Input:

Input: num = 2

Output:

2
Explanation:2 has two divisors: 1 and 2.

Example 3:

Input:

Input: num = 4

Output:

3
Explanation:4 has three divisors: 1, 2, 4.

*/

class Solution {
public:
  int countDivisors(int num) {
    // Implement logic to count divisors of num
    int count = 0;
    for (int i = 1; i <= num; i++) {
      if (num % i == 0) {
        count++;
      }
    }
    return count;
  }
};