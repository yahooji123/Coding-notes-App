

/*

Example
Example 1:

Input: n = 5

Output: true

Explanation:

The number 5 is a prime number because it has no divisors other than 1 and 5 itself.
Example 2:

Input: n = 4

Output: false

Explanation:

The number 4 is not a prime number because it can be divided evenly by 2 (4 = 2 * 2).
Note
The number 1 is not a prime number by definition.
Example 1:

Input:

Input: n = 1

Output:

false
Explanation:1 is not a prime number.

Example 2:

Input:

Input: n = 2

Output:

true
Explanation:2 is the smallest prime number.

Example 3:

Input:

Input: n = 3

Output:

true
Explanation:3 is a prime number.

*/

bool isPrime(int n) {
  // Your code here
  if (n == 1) {
    return false;
  } else {
    for (int i = 2; i <= (n - 1); i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
}