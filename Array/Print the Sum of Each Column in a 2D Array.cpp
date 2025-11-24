
#include<iostream>
#include<vector>
using namespace std;

/*

Input:


Matrix: [[1, 2, 3],
         [4, 5, 6],
         [7, 8, 9]]
Output:


[12, 15, 18]
Explanation:

Sum of 1st column: 1 + 4 + 7 = 12
Sum of 2nd column: 2 + 5 + 8 = 15
Sum of 3rd column: 3 + 6 + 9 = 18
The function should be versatile enough to handle matrices of different sizes, with restrictions given in the constraints.

Additional Example
Input:


Matrix: [[1, 2],
         [3, 4],
         [5, 6]]
Output:


[9, 12]
Explanation:

Sum of 1st column: 1 + 3 + 5 = 9
Sum of 2nd column: 2 + 4 + 6 = 12
Example 1:

Input:

Input: matrix = [[1, 2, 3], [4, 5, 6]]

Output:

5,7,9
Explanation:

Example 2:

Input:

Input: matrix = [[7, 8], [9, 10], [11, 12]]

Output:

27,30
Explanation:

Example 3:

Input:

Input: matrix = [[1, 2], [3, 4]]

Output:

4,6
Explanation:


*/


std::vector<int> columnSums(const std::vector<std::vector<int>>& matrix) {
    // Implement the logic to compute the sum of each column here
    vector<int>ans;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++){
                 sum=sum+matrix[j][i];
        }
     ans.push_back(sum);
    }
    return ans;
}