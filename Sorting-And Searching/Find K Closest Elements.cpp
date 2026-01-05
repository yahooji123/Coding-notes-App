#include <iostream>
#include <vector>
using namespace std;
/*

Example:
Input:

arr = [1, 2, 3, 4, 5]
k = 4
x = 3
Output:

[1, 2, 3, 4]
Explanation: The four integers closest to 3 are 1, 2, 3, and 4. Each has a unique absolute difference with 3 or are smaller numbers at the same difference when compared to others like 5.

Additional Considerations:
Ensure that the function handles edge cases where x is greater or smaller than all values in the array.
The order of the elements in the array should remain ascending in the result list.
Example 1:

Input:

arr = [1,2,3,4,5], k = 4, x = 3

Output:

[1, 2, 3, 4]
Explanation:-

Example 2:

Input:

arr = [1,2,3,4,5], k = 4, x = -1

Output:

[1, 2, 3, 4]
Explanation:-

Constraints

1 <= k <= arr.length
1 <= arr.length <= 10
arr is sorted in ascending order.
-10

*/

// two pointer method

class Solution
{
public:
    vector<int> twoPtrMethod(vector<int> &arr, int k, int x)
    {
        int l = 0, h = arr.size() - 1;
        while (h - l >= k)
        {
            if (x - arr[l] > arr[h] - x)
            {
                l++;
            }
            else
            {
                h--;
            }
        }
        vector<int> ans;
        for (int i = l; i <= h; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        return twoPtrMethod(arr, k, x);
    }
};

// binary search method

class Solution
{
public:
    int lowerBound(vector<int> &arr, int x)
    {
        int start = 0, end = arr.size() - 1;
        int ans = end;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                end = mid - 1;
            }
            else if (x > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }

            return ans;
        }
    }
    vector<int> bs_method(vector<int> &arr, int k, int x)
    {
        // lower bound
        int h = lowerBound(arr, x);
        int l = h - 1;
        while (k--)
        {
            if (l < 0)
            {
                h++;
            }
            else if (h >= arr.size())
            {
                l--;
            }
            else if (x - arr[l] > arr[h] - x)
            {
                h++;
            }
            else
            {
                l--;
            }
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + h);
    }

    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        return bs_method(arr, k, x);
    }
};

// both codes time complexity 0(n)