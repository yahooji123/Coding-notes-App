
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

Example 1:

Input:

Input: arr = [1, 2, 3, 4, 5]

Output:

[5, 4, 3, 2, 1]
Explanation:The array is reversed to [5, 4, 3, 2, 1].

Example 2:

Input:

Input: arr = [10, 20, 30]

Output:

[30, 20, 10]
Explanation:The array is reversed to [30, 20, 10].

Example 3:

Input:

Input: arr = [-1, -2, -3]

Output:

[-3, -2, -1]
Explanation:The array is reversed to [-3, -2, -1].

*/

class Solution
{
public:
  vector<int> reverseArray(const vector<int> &arr)
  {
    // Implement logic to reverse the array
    vector<int> rev = arr;
    int n = arr.size();
    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
      swap(rev[i], rev[j]);
      i++;
      j--;
    }
    return rev;
  }
};