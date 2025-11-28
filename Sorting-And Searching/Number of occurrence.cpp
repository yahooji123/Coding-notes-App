#include <iostream>
#include <vector>
using namespace std;

/*

Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[].

Examples :

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.
Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.

*/

class Solution
{
public:
    int LastOccurence(vector<int> &arr, int x)
    {

        int n = arr.size();
        int s = 0;
        int e = n - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (arr[mid] == x)
            {
                // store and compute
                ans = mid;
                // right
                s = mid + 1;
            }
            else if (x < arr[mid])
            {
                // left
                e = mid - 1;
            }
            else
            {
                // right
                s = mid + 1;
            }
        }
        return ans;
    }

    int firstOccurence(vector<int> &arr, int x)
    {

        int n = arr.size();
        int s = 0;
        int e = n - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (arr[mid] == x)
            {
                // store and compute
                ans = mid;
                // left
                e = mid - 1;
            }
            else if (x < arr[mid])
            {
                // left
                e = mid - 1;
            }
            else
            {
                // right
                s = mid + 1;
            }
        }
        return ans;
    }

    int countFreq(vector<int> &arr, int target)
    {
        // code here
        int first = firstOccurence(arr, target);
        if (first == -1)
            return 0; // element nahi mila
        int last = LastOccurence(arr, target);
        return last - first + 1;
    }
};
