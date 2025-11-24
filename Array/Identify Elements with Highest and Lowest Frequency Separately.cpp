

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Example:
Input:


[4, 4, 1, 2, 2, 2, 3, 3, 3, 3]
Output:


Highest Frequency Element: 3
Lowest Frequency Element: 1
Explanation:

In the given array, the number 3 appears 4 times, which is the highest frequency. On the other hand, the number 1 appears only once, which is the lowest frequency. Even though 2 appears 3 times, 3 is the element with the highest frequency due to the higher count. When dealing with ties, choose the smallest number amongst the tied elements.

Example 1:

Input:

Input: arr = [1, 2, 2, 3, 3, 3]

Output:

{3,1}
Explanation:3 is the mode with the highest frequency.

Example 2:

Input:

Input: arr = [4, 5, 5,5, 6, 6]

Output:

{5,4}
Explanation:5 and 6 have the same frequency, but 5 is smaller.

Example 3:

Input:

Input: arr = [10, 10, 10, 20, 20]

Output:

{10,20}
Explanation:10 is the mode with the highest frequency.



*/

#include <climits>
class Solution
{
public:
    int findMode(vector<int> &v)
    {
        // Implement logic to find mode
        // vector<int> v = arr;
        sort(v.begin(), v.end());
        int maxfreq = 1;
        int mode = v[0];
        int cf = 1;
        int n = v.size();
        for (int i = 1; i < n; i++)
        {
            if (v[i] == v[i - 1])
            {
                cf++;
            }
            else
                cf = 1;
            if (cf > maxfreq)
            {
                // i got new winner
                maxfreq = cf;
                mode = v[i];
            }
        }
        return mode;
    }

    int findlf(vector<int> &v)
    {
        // already sorted because by reference
        int minFre = INT_MAX;
        int least = v[0];
        int cf = 1;

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] == v[i - 1])
                cf++;
            else
            {
                if (cf < minFre)
                {
                    minFre = cf;
                    least = v[i - 1];
                }
                cf = 1;
            }
        }

        // do'not forget that last element could be the least
        if (cf < minFre)
        {
            minFre = cf;
            least = v[v.size() - 1];
        }
        return least;
    }

    pair<int, int> highestAndLowestFrequency(vector<int> &arr)
    {
        // Implement logic to find elements with highest and lowest frequency
        int hf = findMode(arr);
        int lf = findlf(arr);
        return {hf, lf}; // Placeholder return; user will complete the logic
    }
};