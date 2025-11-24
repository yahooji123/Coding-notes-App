


/*

Example
Example 1:
Input:


num = 5
Output:


-5
Explanation:


The binary representation of 5 is `00000101`. Inverting the bits gives `11111010`. Adding 1 results in `11111011`, which is `-5` in decimal.
Example 2:
Input:


num = 1
Output:


-1
Explanation:


The binary representation of 1 is `1`. Inverting the bits gives `0`. Adding 1 results in `1`, which represents `-1` in 2's complement for a single bit.
Example 1:

Input:

Input: num = 5

Output:

-5
Explanation:2's complement of 5 is -5.

Example 2:

Input:

Input: num = 10

Output:

-10
Explanation:2's complement of 10 is -10.

Example 3:

Input:

Input: num = 1

Output:

-1
Explanation:2's complement of 1 is -1.

*/

class Solution {
public:
  int twosComplement(int num) {
    // Implement logic to find 2's complement of num
    // 2` completement +1

    int one_sComp = ~num;
    int _2_Comp = one_sComp + 1;

    return _2_Comp;
  }
};