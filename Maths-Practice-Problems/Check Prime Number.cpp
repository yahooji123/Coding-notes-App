
#include<iostream>
using namespace std;

/*

Example
Input: num = 29

Output: True

Explanation: 29 is a prime number because it is only divisible by 1 and 29.

Input: num = 35

Output: False

Explanation: 35 is not a prime number because it has divisors 1, 5, 7, and 35.

Example 1:

Input:

Input: num = 2

Output:

Yes
Explanation:2 is prime.

Example 2:

Input:

Input: num = 4

Output:

No
Explanation:4 is not prime.

Example 3:

Input:

Input: num = 5

Output:

Yes
Explanation:5 is prime.


*/


class Solution {
public:
  string isPrime(int num) {
    // Implement logic to check if num is prime
    if (num == 1) {
      return "No";
      // check
    }
    if (num == 2 || num == 3) {
      return "Yes";
    }
    int start = 2;
    int end = num - 1;

    for (int i = start; i <= end; i++) {
      if (num % i == 0) {
        return "No";
      }
    }
    return "Yes";
  }
};