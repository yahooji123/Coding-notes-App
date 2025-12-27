#include <iostream>
#include <string>
using namespace std;

/*

Input: s = "abaab"
Output: 3
Explanation: All palindromic substrings (of length > 1) are: "aba", "aa", "baab".
Input: s = "aaa"
Output: 3
Explanation: All palindromic substrings (of length > 1) are: "aa", "aa", "aaa".
Input: s = "abbaeae"
Output: 4
Explanation: All palindromic substrings (of length > 1) are: "bb", "abba", "aea", "eae".

*/

class Solution
{
public:
    int checkPalindrome(string s, int i, int j)
    {
        int count = 0;
        while (i >= 0 && j < s.length() && s[i] == s[j])
        {
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countPS(string &s)
    {
        int count = 0;
        for (int centre = 0; centre < s.length(); centre++)
        {
            // odd
            int i = centre;
            int j = centre;
            int oddLengthPalindromeCount = checkPalindrome(s, i, j);

            // even
            i = centre;
            j = centre + 1;
            int evenlengthPalindromeCount = checkPalindrome(s, i, j);

            count = count + oddLengthPalindromeCount + evenlengthPalindromeCount;
        }

        return count - s.length();
    }
};
