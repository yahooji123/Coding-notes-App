#include <iostream>
using namespace std;

/*

* * * * *
* * * * *
* * * * *

*/

/*

Example 1:

Input:

n=2, m=5

Output:

* * * * *
* * * * *
Explanation:A solid rectangle of 2 rows and 5 columns.

Example 2:

Input:

n=3, m=7

Output:

* * * * * * *
* * * * * * *
* * * * * * *
Explanation:A solid rectangle of 3 rows and 7 columns.

Example 3:

Input:

n=5, m=3

Output:

* * *
* * *
* * *
* * *
* * *
Explanation:A solid rectangle of 5 rows and 3 columns.

*/

class Solution
{
public:
    void printSolidRectangle(int n, int m)
    {
        // Implement the pattern printing logic here
        for (int row = 1; row <= n; row++)
        {
            for (int colm = 1; colm <= m; colm++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
};