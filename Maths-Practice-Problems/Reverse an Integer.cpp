

#include<iostream>
#include <climits>

using namespace std;

/*

Examples:
Example 1:
Input: x = 123
Output: 321
Explanation: Reversing the digits of 123 gives 321.
Example 2:
Input: x = -123
Output: -321
Explanation: Reversing the digits of -123 gives -321.
Example 3:
Input: x = 120
Output: 21
Explanation: Reversing the digits of 120 gives 021, which is 21.
Note:
Assumptions about the environment restrict you from storing integers larger than 32 bits, which means you must handle overflow scenarios by returning 0.

Example 1:

Input:

Input: x = 123

Output:

321
Explanation:Reversing 123 gives 321.

Example 2:

Input:

Input: x = -456

Output:

-654
Explanation:Reversing -456 gives -654.

Example 3:

Input:

Input: x = 100

Output:

1
Explanation:Reversing 100 removes leading zeros, giving 1.

*/

class Solution {
public:
    int reverse(int n) {
       
        if (n == 0) {
            return 0;
        }

        bool flag;
        if (n > 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        n = abs(n);

        long long ans = 0;   
        while (n != 0) {
            int digit = n % 10;
            ans = ans * 10 + digit;
            n = n / 10;
        }

        if (ans > INT_MAX || ans < INT_MIN) {
            return 0;
        }

        if (flag == 0) {
            ans = -ans;
        }
        return (int)ans;
    }
};
