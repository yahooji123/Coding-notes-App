

#include <iostream>
#include <vector>
using namespace std;


/*

Example
Example 1:
Input: arr = [1, 2, 3, 4, 5]
Output: [10, 20, 30, 40, 50]
Explanation: Each element of the array [1, 2, 3, 4, 5] is multiplied by 10, resulting in the array [10, 20, 30, 40, 50].

Example 2:
Input: arr = [0, -1, -100]
Output: [0, -10, -1000]
Explanation: The elements of the array [0, -1, -100] are multiplied by 10, resulting in [0, -10, -1000].

Task
Write a function that takes an integer array and returns a new array with each element multiplied by 10.

Example 1:

Input:

Input: arr = [1, 2, 3, 4, 5]

Output:

[10, 20, 30, 40, 50]
Explanation:Each element is multiplied by 10.

Example 2:

Input:

Input: arr = [0, -1, -2, 3, 4]

Output:

[0, -10, -20, 30, 40]
Explanation:Negative and zero values also get multiplied correctly.

Example 3:

Input:

Input: arr = [10, 20, 30]

Output:

[100, 200, 300]
Explanation:All numbers are multiplied by 10.

*/



vector<int> multiplyByTen(const vector<int> &arr) {
  // Start completing the function
  vector<int> arrCopy = arr;
  int size = arrCopy.size();

  for (int i = 0; i < size; i++) {

    arrCopy[i] = arrCopy[i] * 10;
  }
  return arrCopy;
}