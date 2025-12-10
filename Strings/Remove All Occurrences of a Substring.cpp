#include <iostream>
#include <algorithm>
using namespace std;

/*

Example:
Example 1:

Input: s = "ababcab", part = "ab"
Output: "c"
Explanation:
First, remove "ab" from "ababcab", resulting in "abcab".
Remove "ab" again from "abcab", resulting in "cab".
Finally, remove "ab" from "cab", leaving "c".
Example 2:

Input: s = "abcd", part = "xyz"
Output: "abcd"
Explanation: Since "xyz" is not present in "abcd", the string remains unchanged.
The objective is to remove the specified part from the original string until it can no longer be found.

Complete the function to achieve this by efficiently removing the specified substring repeatedly.

Example 1:

Input:

s='daabcbaabcbc', part='abc'

Output:

dab
Explanation:Removing 'abc' gives 'dabaabcbc', then removing 'abc' again gives 'dab'.

Example 2:

Input:

s='axxxxyyyyb', part='xy'

Output:

ab
Explanation:Removing 'xy' repeatedly results in 'ab'.

Example 3:

Input:

s='mississippi', part='issip'

Output:

misspi
Explanation:Removing 'issip' from 'mississippi' results in 'mispi'.

*/

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        // jab tak maiin string k andar part string
        // milti rahegi, tab tak main use remove krta rahunga
        //  tab ruk jaunga

        while (s.find(part) != -1)
        {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};