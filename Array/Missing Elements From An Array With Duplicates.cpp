#include <iostream>
#include <vector>
using namespace std;

/*

Given an array nums containing n integers where some elements may be duplicated and the integers are supposed to be in the range 1 to n, your task is to return the list of integers that are missing from the array.

The size of the array is n, and each integer in the array is between 1 and n inclusive.

Note
The algorithm should ideally run in O(n) time and use O(1) additional space.
Example 1:

Input:

n=8 nums=[4,3,2,7,8,2,3,1]

Output:

5 6
Explanation:Numbers 1‒8 should all appear; 5 and 6 are absent while 2 and 3 are duplicated.

Example 2:

Input:

n=4 nums=[1,2,3,4]

Explanation:Array already contains each value 1…4 exactly once, so the result list is empty.

Example 3:

Input:

n=4 nums=[2,2,2,2]

Output:

1 3 4
Explanation:Only 2 is present (four times); 1, 3, 4 are missing.

*/

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};