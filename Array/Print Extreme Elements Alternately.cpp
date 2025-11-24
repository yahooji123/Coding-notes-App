
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

/*

Example
Input:


[1, 3, 2, 4, 5]
Output:


1 5 2 4 3
Explanation:

Sorting the array gives: [1, 2, 3, 4, 5].
Start by picking the smallest element (1), then the largest element (5).
Continue by picking the next smallest (2) and the next largest (4).
Finally, pick the remaining element (3).
Your goal is to implement this alternating order display in a function that operates efficiently even for larger arrays.

Example 1:

Input:

Input: arr = [1, 2, 3, 4, 5]

Output:

1 5 2 4 3
Explanation:Sorted array: [1,2,3,4,5]. Start with smallest (1), then largest (5), then second smallest (2), second largest (4), and finally the middle element (3).

Example 2:

Input:

Input: arr = [5, 4, 3, 2, 1]

Output:

1 5 2 4 3
Explanation:The array gets sorted first to [1,2,3,4,5], then processed in the same manner.

Example 3:

Input:

Input: arr = [10, 20, 30, 40, 50, 60]

Output:

10 60 20 50 30 40
Explanation:Start from smallest (10), largest (60), second smallest (20), second largest (50), etc.

*/



class Solution {
public:
  vector<int> printExtremeElementsAlternately(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int> ans;
    int i = 0;
    int j = n - 1;
    while (i <= j) {
      ans.push_back(arr[i]);
      ans.push_back(arr[j]);
      i++;
      j--;
    }
    return ans;
  }
};