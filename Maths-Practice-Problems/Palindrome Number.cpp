#include<iostream>
using namespace std;
/*
Example:
Input:


121
Output:


true
Explanation: 121 reads the same forwards and backwards, hence it is a palindrome.

Input:


123
Output:


false
Explanation: 123 does not read the same forwards and backwards, so it is not a palindrome.

Example 1:

Input:

Input: num = 121

Output:

Yes
Explanation:121 is a palindrome.

Example 2:

Input:

Input: num = 123

Output:

No
Explanation:123 is not a palindrome.

Example 3:

Input:

Input: num = 1221

Output:

Yes
Explanation:1221 is a palindrome.

*/

class Solution {
public:
  string isPalindrome(int num) {
    // Implement logic to check if num is a palindrome
    // Placeholder return; user will complete the logic
    int c = num;
    int rev = 0;
    while (num != 0) {
      int digit = num % 10;
      rev = rev * 10 + digit;
      num = num / 10;
    }

    if (rev == c) {
      return "Yes";
    } else {
      return "No";
    }
  }
};