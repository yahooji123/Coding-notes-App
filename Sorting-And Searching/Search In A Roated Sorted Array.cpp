
#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1


*/

class Solution
{
public:
    int findPivotIndex(vector<int> &nums)
    {

        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while (s <= e)
        {

            int mid = (s + e) / 2;

            // single case
            if (s == e)
            {
                return mid;
            }

            //  mid is pivot
            if (mid + 1 < n && nums[mid] > nums[mid + 1])
            {
                return mid;
            }

            //` mid is in rotated part (line-2)
            if (nums[mid] < nums[s])
            {
                e = mid - 1; // go left
            }

            else
            {
                s = mid + 1; // go right
            }
        }

        // no pivot means array is not rotated
        return -1;
    }

    int binarySearch(int s, int e, vector<int> &nums, int target)
    {

        while (s <= e)
        { // <-- bas ye while add kiya
            int mid = (s + e) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            if (target > nums[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {

        int pivotIndex = findPivotIndex(nums);
        // yaha tum baad me code likhoge

        /*
            for l-1
              s = 0
              end = pivotIndex

            for l-2
              s = pivotIndex + 1
              end = n - 1;
        */
        int n = nums.size();

        if (target >= nums[0] && target <= nums[pivotIndex])
        {
            int ans = binarySearch(0, pivotIndex, nums, target);
            return ans;
        }
        /*
          for l-2
              s = pivotIndex + 1
              end = n - 1;
        */
        else
        {
            int ans = binarySearch(pivotIndex + 1, n - 1, nums, target);
            return ans;
        }

        return -1;
    }
};
