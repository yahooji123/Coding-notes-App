#include <iostream>
#include <string>
using namespace std;

/*

Example 1:

Input:

Input: haystack = 'hello', needle = 'll'

Output:

2
Explanation:The substring 'll' starts at index 2 in 'hello'.

Example 2:

Input:

Input: haystack = 'aaaaa', needle = 'bba'

Output:

-1
Explanation:'bba' does not occur in 'aaaaa'.

Example 3:

Input:

Input: haystack = 'mississippi', needle = 'issip'

Output:

4
Explanation:The substring 'issip' starts at index 4.

*/

class Solution
{
public:
    int strStr(const string &haystack, const string &needle)
    {
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i <= n - m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (needle[j] != haystack[i + j])
                {
                    break;
                }
                if (j == m - 1)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};