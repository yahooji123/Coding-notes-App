
#include<iostream>
using namespace std;
/*

Example
Input: num = 16

Output: true

Explanation: 16 is 24, which is a power of 2.

Input: num = 18

Output: false

Explanation: 18 cannot be expressed as a power of 2.

Note
You need to write an efficient solution; using properties of numbers and bit manipulation could be beneficial here.
Consider edge cases and large values, within the given constraints.
Example 1:

Input:

Input: num = 1

Output:

Yes
Explanation:1 is 2^0, hence a power of 2.

Example 2:

Input:

Input: num = 2

Output:

Yes
Explanation:2 is 2^1, hence a power of 2.

Example 3:

Input:

Input: num = 3

Output:

No
Explanation:3 is not a power of 2.

*/



class Solution {
public:
    string isPowerOfTwo(int num) {
        if (num <= 0) {
            return "No";   // negative numbers and 0 are not powers of 2
        }

        if ((num & (num - 1)) == 0) {
            return "Yes";
        } else {
            return "No";
        }
    }
};
