


/*

Example
Input:


6 8  
Output:


24  
Explanation: The smallest number that both 6 and 8 divide without leaving a remainder is 24.

More Examples
Input:


15 20  
Output:


60  
Explanation: The smallest number that both 15 and 20 divide exactly is 60.

Example 1:

Input:

Input: a = 4, b = 5

Output:

20
Explanation:LCM of 4 and 5 is 20.

Example 2:

Input:

Input: a = 6, b = 8

Output:

24
Explanation:LCM of 6 and 8 is 24.

Example 3:

Input:

Input: a = 15, b = 20

Output:

60
Explanation:LCM of 15 and 20 is 60.

*/

class Solution {
public:
  int findLCM(int a, int b) {
    // Implement logic to find LCM of a and b
    int l = (a > b) ? a : b;
    int max = a * b;

    for (int i = l; i <= max; i++) {
      if (i % a == 0 && i % b == 0) {
        return i;
      }
    }
  }
};