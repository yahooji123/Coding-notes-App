
#include<iostream>
#include<vector>
using namespace std;
/*

Example
Input:


digits = [5, 8, 3, 2, 9]
Output:


98532
Explanation:

To achieve the largest possible number with the digits [5, 8, 3, 2, 9], they are rearranged in descending order resulting in the number 98532.

Example 1:

Input:

Input: digits = [1, 2, 3]

Output:

321
Explanation:The digits are combined as 3 → 2 → 1 forming 321.

Example 2:

Input:

Input: digits = [4, 5, 6, 7]

Output:

7654
Explanation:The digits are combined as 7 → 6 → 5 → 4 forming 7654.

Example 3:

Input:

Input: digits = [9, 8, 7, 6]

Output:

9876
Explanation:The digits are combined as 9 → 8 → 7 → 6 forming 9876.



*/


class Solution {
public:
    int createLargestNumber(vector<int>& digits) {
        int n = digits.size();

        // Bubble sort style descending order
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (digits[j] < digits[j + 1]) {
                    // Swap adjacent values
                    int temp = digits[j];
                    digits[j] = digits[j + 1];
                    digits[j + 1] = temp;
                }
            }
        }

        // Combine digits to form number
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum * 10 + digits[i];
        }

        return sum;
    }
};
