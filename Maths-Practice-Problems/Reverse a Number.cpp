



/*

Example
Example 1:
Input: num = 12345
Output: 54321
The digits 12345 become 54321 when reversed.

Example 2:
Input: num = 100
Output: 1
The digits 100 become 001, but leading zeros are not part of the number, thus 1 is returned.

Example 1:

Input:

Input: num = 123

Output:

321
Explanation:Reversing 123 gives 321.

Example 2:

Input:

Input: num = 456

Output:

654
Explanation:Reversing 456 gives 654.

Example 3:

Input:

Input: num = 78910

Output:

1987
Explanation:Reversing 78910 gives 1987.

*/

class Solution {
public:
  int reverseNumber(int num) {
    // Implement logic to reverse the number
    int ans = 0;
    while (num != 0) {
      int digit = num % 10;
      ans = ans * 10 + digit;
      num = num / 10;
    }
    return ans;
  }
};