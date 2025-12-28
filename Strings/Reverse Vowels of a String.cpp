#include <iostream>
#include <string>
using namespace std;

/*

Example
Input

s = "hello"
Output

"holle"
Explanation
The vowels in "hello" are 'e' and 'o'. When these are reversed, their positions swap, resulting in "holle".

Input

s = "leetcode"
Output

"leotcede"
Explanation
In "leetcode", the vowels 'e', 'e', and 'o' are reversed, leading to the string "leotcede".

Example 1:

Input:

s = 'IceCreAm'

Output:

AceCreIm
Explanation:Vowels ['I', 'e', 'e', 'A'] reversed result in 'AceCreIm'.

Example 2:

Input:

s = 'hello'

Output:

holle
Explanation:Vowels ['e', 'o'] reversed result in 'holle'.

Example 3:

Input:

s = 'abcdef'

Output:

ebcdaf
Explanation:Vowels ['a', 'e'] reversed result in 'abcdef'.

*/
class Solution
{
public:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string reverseVowels(string &s)
    {
        int l = 0, h = s.size() - 1;

        while (l < h)
        {
            if (isVowel(s[l]) && isVowel(s[h]))
            {
                swap(s[l], s[h]);
                l++;
                h--;
            }
            else if (isVowel(s[l]) == 0)
            {
                l++;
            }
            else
            {
                h--;
            }
        }
        return s;
    }
};