#include <iostream>
using namespace std;

/*

****
****
****
****

*/

class Solution
{
public:
    void printSquare(int n)
    {
        // User to fill this part
        for (int row = 1; row <= n; row++)
        {
            for (int colm = 1; colm <= n; colm++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
};
