
#include <iostream>
#include <vector>
using namespace std;

/*

Example
Input: [1, 2, 3, 4, 6, 5, 7, 8]
Output: 4
In the given input, elements from index 0 to 3 (1, 2, 3, 4) are in non-decreasing order. The element at index 4 is 6, which is followed by 5 at index 5, violating the non-decreasing order since 6 is greater than 5. Hence, index 4 is the first unsorted element.

Try to identify this pattern and apply the logic to solve the problem for any given input array.

Example 1:

Input:

Input: arr = [1, 2, 3, 4, 5]

Output:

-1
Explanation:The array is already sorted.

Example 2:

Input:

Input: arr = [10, 20, 30, 25, 40]

Output:

2
Explanation:First unsorted element is at index 2 (30 > 25).

Example 3:

Input:

Input: arr = [5, 4, 3, 2, 1]

Output:

0
Explanation:First unsorted element is at index 0 (5 > 4).

*/

class Solution
{
public:
    int findFirstUnsortedIndex(const vector<int> &arr)
    {
        // Implement logic to find first unsorted index

        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return i;
            }
        }

        return -1;
    }
};