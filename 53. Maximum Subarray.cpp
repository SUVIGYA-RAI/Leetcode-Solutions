#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int end = nums[0];
            int far = nums[0];
            for (int i=1; i<n; i++) {
                end = max(nums[i], end+nums[i]);
                far = max(end,far);
            }
            return far;
        }
    };