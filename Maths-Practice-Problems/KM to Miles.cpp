

/*

Example:

Suppose the input is: 5

The expected output would be: 3.106855

Note:

Always ensure your output is a floating-point number. The resultant conversion should preserve the precision up to at least six decimal places.
Example 1:

Input:

Input: Km = 1

Output:

0.621371
Explanation:Converting 1 KM gives 0.621371 Miles.

Example 2:

Input:

Input: Km = 10

Output:

6.21371
Explanation:Converting 10 KM gives 6.21371 Miles.

Example 3:

Input:

Input: Km = 50

Output:

31.0686
Explanation:Converting 50 KM gives 31.0686 Miles.

*/


class Solution {
public:
    double convertKmToMiles(int Km) {
       return  (double)Km * 0.621371;
    };
};