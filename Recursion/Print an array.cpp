#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:
Input: arr = [1, 2, 3, 4, 5]
Output: 1 2 3 4 5
Example 2:
Input: arr = [10, 20, 30]
Output: 10 20 30


*/

class Solution
{
public:
    void printRecursive(vector<int> &arr, int idx)
    {
        if (idx == arr.size())
            return;
        cout << arr[idx] << " ";
        return printRecursive(arr, idx + 1);
    }

    void printArray(vector<int> &arr) { printRecursive(arr, 0); }
};
