


/*

Example
Example 1:
Input:


n = 3
Output:


4
Explanation:

The binary representations of numbers from 1 to n are:

1 (1): 1
2 (2): 10
3 (3): 11
The total number of set bits in these numbers is 1 + 1 + 2 = 4.

Example 2:
Input:


n = 5
Output:


7
Explanation:

The binary representations are:

1: 1
2: 10
3: 11
4: 100
5: 101
The total set bits = 1 + 1 + 2 + 1 + 2 = 7.

Your goal is to find a more efficient solution than directly counting the bits of each individual number.

Example 1:

Input:

Input: n = 1

Output:

1
Explanation:Binary representation: 1 → 1 set bit. Total set bits: 1.

Example 2:

Input:

Input: n = 2

Output:

2
Explanation:Binary: 1 (1 set bit), 10 (1 set bit). Total: 1+1 = 2.

Example 3:

Input:

Input: n = 3

Output:

4
Explanation:Binary: 1 (1), 10 (1), 11 (2). Total: 1+1+2 = 4.

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int countTotalSetBits(int n) {
        int total = 0;
        for (int i = 1; i <= n; i++) {
            int x = i;
            while (x > 0) {
                if (x % 2 == 1)  
                    total++;
                x = x / 2;       
            }
        }
        return total;
    }
};