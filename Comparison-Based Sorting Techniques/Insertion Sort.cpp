#include <iostream>
#include <vector>
using namespace std;

/*

Examples:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: The sorted array will be [1, 3, 4, 7, 9].
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: The sorted array will be [1, 2, 3, 4, 5, 6, 7, 8, 9, 10].
Input: arr[] = [4, 1, 9]
Output: [1, 4, 9]
Explanation: The sorted array will be [1, 4, 9].

*/

class Solution
{
public:
    void insertionSort(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int pivot = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > pivot)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = pivot;
        }
    }
};
