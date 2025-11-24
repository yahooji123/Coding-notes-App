
#include<iostream>
#include <cmath>
using namespace std;

/*

Example
Input:


153
Output:


true
Note
Check if the number that is inputted is a Narcissistic number by calculating the sum of its digits each raised to the power of the number of digits.

Example 1:

Input:

Input: num = 153

Output:

Yes
Explanation:153 is equal to 1^3 + 5^3 + 3^3, so it is Narcissistic.

Example 2:

Input:

Input: num = 9474

Output:

Yes
Explanation:9474 is equal to 9^4 + 4^4 + 7^4 + 4^4.

Example 3:

Input:

Input: num = 123

Output:

No
Explanation:123 is not Narcissistic.

*/


class Solution {
public:
  string isNarcissistic(int num) {
    // Implement logic to check if num is Narcissistic
    int original = num;
    int sum = 0;
    int count = 0;
    int copy = num;

    while (copy != 0) {
      count++;
      copy = copy / 10;
    }
    while (num != 0) {
      int digit = num % 10;
      sum = sum + pow(digit, count);
      num = num / 10;
    }
    return (sum == original) ? "Yes" : "No";
  }
};
