#include <iostream>
#include <vector>
using namespace std;

//   leet code->647     https: // leetcode.com/problems/palindromic-substrings/description/

/*

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

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
    int countSubstrings(string s)
    {
        int count = 0;
        for (int centre = 0; centre < s.length(); centre++)
        {
            // center ->odd and even case
            // odd
            int i = centre;
            int j = centre;
            int oddLengthPalindromeCount = checkPalindrome(s, i, j);
            // even wala case
            i = centre;
            j = centre + 1;
            int evenlengthPalindromeCount = checkPalindrome(s, i, j);
            count = count + oddLengthPalindromeCount + evenlengthPalindromeCount;
        }
        return count;
    }
};
