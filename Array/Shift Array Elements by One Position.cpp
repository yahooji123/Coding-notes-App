

/*

Example 1:

Input:

Input: arr = [1]

Output:

[1]
Explanation:A single-element array remains the same after shifting.

Example 2:

Input:

Input: arr = [1, 2]

Output:

[2, 1]
Explanation:Array with two elements shifted by one position.

Example 3:

Input:

Input: arr = [1, 2, 3]

Output:

[3, 1, 2]
Explanation:Array shifted by one position.


*/


class Solution {
public:
  vector<int> shiftRight(const vector<int> &arr) {
    // Implement logic to shift array elements by one position
    vector<int> arr2 = arr;
    int n = arr2.size();
    int lastelement = arr2[n - 1];

    for (int i = n - 1; i >= 0; i--) {
      if (i != 0) {
        arr2[i] = arr2[i - 1];
      } else {
        arr2[0] = lastelement;
      }
    }
    return arr2;
  }
};

