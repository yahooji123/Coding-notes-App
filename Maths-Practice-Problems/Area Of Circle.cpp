

/*

Example:
Input:


radius = 5
Output:


78.54
Explanation:

Given the radius of 5, the area ( A = \pi \times 5^2 = 78.53975 ) is rounded to 78.54.

Example 1:

Input:

Input: radius = 1

Output:

3
Explanation:Area of a circle with radius 1 is approximately 3.

Example 2:

Input:

Input: radius = 2

Output:

12
Explanation:Area of a circle with radius 2 is approximately 12.

Example 3:

Input:

Input: radius = 3

Output:

28
Explanation:Area of a circle with radius 3 is approximately 28.

*/


class Solution {
public:
    int areaOfCircle(int radius) {
       return 3.14*radius*radius;
    }
};