

/*

Example
Input:


N = 10
Output:


[2, 3, 5, 7]
Explanation:

When 1 through 10 are evaluated, the numbers 2, 3, 5, and 7 meet the criteria of being prime numbers, as they cannot be divided evenly by any other numbers except for 1 and the number itself.
You need to ensure that your function effectively computes all the prime numbers for a given N, especially considering large values of N.

Example 1:

Input:

Input: N = 10

Output:

2 3 5 7
Explanation:Prime numbers up to 10 are: 2, 3, 5, 7.

Example 2:

Input:

Input: N = 20

Output:

2 3 5 7 11 13 17 19
Explanation:Prime numbers up to 20 are: 2, 3, 5, 7, 11, 13, 17, 19.

Example 3:

Input:

Input: N = 1

Explanation:There are no prime numbers up to 1.

*/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> printPrimes(int N) {
        vector<int> primes;

        for (int num = 2; num <= N; num++) {
            bool isPrime = true;

            for (int i = 2; i*i <= num; i++) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) {
                primes.push_back(num);
            }
        }

        return primes;
    }
};
