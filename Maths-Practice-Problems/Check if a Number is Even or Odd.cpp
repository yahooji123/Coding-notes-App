
#include<iostream>
using namespace std;

/*

Examples
Example 1

Input: 4

Output: Even

Here, the number 4 is divisible by 2 without a remainder, thus it is classified as an even number.

Example 2

Input: 7

Output: Odd

Here, the number 7 leaves a remainder of 1 when divided by 2, thus it is classified as an odd number.

The challenge is straightforward and focuses on working with the modulus operator to determine the nature of the number.

Function Signature
def check_even_odd(num: int) -> str: pass

Example 1:

Input:

Input: num = 4

Output:

Even
Explanation:4 is even.

Example 2:

Input:

Input: num = 7

Output:

Odd
Explanation:7 is odd.

Example 3:

Input:

Input: num = 0

Output:

Even
Explanation:0 is considered even.

*/


class Solution {
public:
  string checkEvenOdd(int num) {
    // Implement logic to check if num is even or odd
    if (num & 1) {
      return "Odd";

    } else {
      return "Even";
    }
  }
};