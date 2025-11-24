
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*

Example 1:

Input:

Input: nums = [-1, 0, 1, 2, -1, -4]

Output:

[[-1, -1, 2], [-1, 0, 1]]
Explanation:

Example 2:

Input:

Input: nums = [0, 1, 1]

Output:

[]
Explanation:

Example 3:

Input:

Input: nums = [0, 0, 0]

Output:

[[0, 0, 0]]
Explanation:



*/

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    // Implementation will go here
    vector<vector<int>> ans;
    int n = nums.size();

    // do sort before hand
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < n; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        for (int k = j + 1; k < n; k++) {
          if (k > j + 1 && nums[k] == nums[k - 1]) {
            continue;
          }
          int first = nums[i];
          int second = nums[j];
          int third = nums[k];
          int sum = first + second + third;
          if (sum == 0) {
            vector<int> temp;
            temp.push_back(first);
            temp.push_back(second);
            temp.push_back(third);
            ans.push_back(temp);
          }
        }
      }
    }
    return ans;
  }
};