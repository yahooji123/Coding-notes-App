



/*


Example
Input:

arr = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

Output:

[6, 15, 24]

Explanation:

The sum of the first row is 1 + 2 + 3 = 6.
The sum of the second row is 4 + 5 + 6 = 15.
The sum of the third row is 7 + 8 + 9 = 24.
Therefore, the output is [6, 15, 24].

Additional Example
Input:

arr = [[1], [2, 2], [3, 3, 3]]

Output:

[1, 4, 9]

Explanation:

The sum of the first row is 1.
The sum of the second row is 2 + 2 = 4.
The sum of the third row is 3 + 3 + 3 = 9.
Thus, the resulting output is [1, 4, 9].

Example 1:

Input:

Input: arr = [[1, 2, 3], [4, 5, 6]]

Output:

6,15
Explanation:

Example 2:

Input:

Input: arr = [[7, 8], [9, 10], [11, 12]]

Output:

15,19,23
Explanation:

Example 3:

Input:

Input: arr = [[1, 2], [3, 4]]

Output:

3,7
Explanation:



*/


#include <vector>

std::vector<int> rowSums(const std::vector<std::vector<int>>& arr) {
    std::vector<int> ans;
    int n = arr.size(); 
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < arr[i].size(); j++) { // columns of row i
            sum += arr[i][j];
        }
        ans.push_back(sum);
    }
    return ans;
}
