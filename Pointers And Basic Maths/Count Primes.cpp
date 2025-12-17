#include <iostream>
#include <vector>
using namespace std;

// leetcode->204 -> https://leetcode.com/problems/count-primes/description/

/*

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0


Constraints:

0 <= n <= 5 * 106

*/

class Solution
{
public:
    int countPrimes(int n)
    {

        if (n == 0)
            return 0;
        vector<bool> prime(n, true); // all are prime parked already
        prime[0] = prime[1] == false;
        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                ans++;
                int j = 2 * i;
                while (j < n)
                {
                    prime[j] = false;
                    j += i;
                }
            }
        }
        return ans;
    }
};