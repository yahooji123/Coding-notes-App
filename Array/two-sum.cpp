// QUESTION: TWO SUM
// PLATFORM: LEETCODE
// LINK: https://leetcode.com/problems/two-sum/
// DATE: 24-11-2025
// LEVEL: EASY
// NOTES: Used hashmap to store (value → index).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (mp.count(rem)) return {mp[rem], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};
