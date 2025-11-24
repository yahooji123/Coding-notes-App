

#include <iostream>
#include <vector>
using namespace std;

/*
Example:
Suppose you have an array: [2, 4, 6, 8]

The sum of the array elements is 2 + 4 + 6 + 8 = 20.
The number of elements in the array is 4.
Therefore, the average is 20 / 4 = 5.0.
Your task is to implement a function that calculates this average for any given array of integers.

Example 1:

Input:

Input: arr = [2, 4, 6, 8, 10]

Output:

6
Explanation:Average of [2, 4, 6, 8, 10] is 6.

Example 2:

Input:

Input: arr = [1, -1, 1, -1]

Output:

0
Explanation:Average of [1, -1, 1, -1] is 0.

Example 3:

Input:

Input: arr = [5, 10, 15]

Output:

10
Explanation:Average of [5, 10, 15] is 10.

*/

class Solution
{
public:
    double findAverage(const vector<int> &arr)
    {
        // Implement logic to find the average
        double sum = 0;
        int length = arr.size();
        for (int i = 0; i < length; i++)
        {
            sum = sum + arr[i];
        }

        double avg = sum / length;
        return avg;
    }
};