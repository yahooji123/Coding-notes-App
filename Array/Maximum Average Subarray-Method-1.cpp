
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*

Example 1:

Input:

nums=[1,12,-5,-6,50,3] k=4

Output:

12.75
Explanation:The subarray [12,-5,-6,50] has the maximum average 12.75.

Example 2:

Input:

nums=[5] k=1

Output:

5
Explanation:Only one subarray possible; average is 5.0.

Example 3:

Input:

nums=[-1,-12,-5,-6,-50] k=2

Output:

-5.5
Explanation:Subarray [-5,-6] gives average –5.5, highest among all pairs.

*/

#include <climits>
class Solution
{
public:
    double bruteForce(vector<int> &nums, int k)
    {

        int maxSum = INT_MIN;

        for (int i = 0; i <= nums.size() - k; i++)
        {
            int sum = 0;
            for (int j = i; j < i + k; j++)
            {
                sum += nums[j];
            }
            maxSum = max(maxSum, sum);
        }

        return maxSum / (double)k;
    }

    double findMaxAverage(vector<int> &nums, int k)
    {
        return bruteForce(nums, k);
    }
};
