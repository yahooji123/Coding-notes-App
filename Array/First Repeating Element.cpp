#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// gfg -> https://www.geeksforgeeks.org/problems/first-repeating-element4018/1

/*

Given an array arr[], find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

Note:- The position you return should be according to 1-based indexing.

Examples:

Input: arr[] = [1, 5, 3, 4, 3, 5, 6]
Output: 2
Explanation: 5 appears twice and its first appearance is at index 2 which is less than 3 whose first the occurring index is 3.
Input: arr[] = [1, 2, 3, 4]
Output: -1
Explanation: All elements appear only once so answer is -1.

*/

class Solution
{
public:
    int firstRepeated(vector<int> &arr)
    {
        unordered_map<int, int> hash;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            hash[arr[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (hash[arr[i]] > 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
};

// second solution without using unordered_map

class Solution
{
public:
    int firstRepeated(vector<int> &arr)
    {
        int n = arr.size();

        int hash[100000] = {0}; // hash array (size as per constraint)

        // frequency count
        for (int i = 0; i < n; i++)
        {
            hash[arr[i]]++;
        }

        // first repeating element (1-based index)
        for (int i = 0; i < n; i++)
        {
            if (hash[arr[i]] > 1)
            {
                return i + 1;
            }
        }

        return -1;
    }
};
