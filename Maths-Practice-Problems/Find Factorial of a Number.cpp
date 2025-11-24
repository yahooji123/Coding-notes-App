

/*

Examples:

Example 1:

Input: 5
Output: 120
Explanation: 5! = 5 × 4 × 3 × 2 × 1 = 120.

Example 2:

Input: 0
Output: 1
Explanation: 0! is defined to be 1 by convention.
Factorials grow very quickly, therefore, to avoid overflow issues, we limit the input number n to a maximum of 20. This ensures results fit within standard data type capacities in most programming languages.

Example 1:

Input:

Input: num = 0

Output:

1
Explanation:Factorial of 0 is defined as 1.

Example 2:

Input:

Input: num = 1

Output:

1
Explanation:Factorial of 1 is 1.

Example 3:

Input:

Input: num = 5

Output:

120
Explanation:5! = 120.


*/

class Solution {
public:
  unsigned long long factorial(int num) {
    unsigned long long fact = 1; // start with 1
    if (num == 0 || num == 1) {
      return 1;
    }
    for (int i = num; i > 1; i--) {
      fact = fact * i;
    }
    return fact;
  }
};
