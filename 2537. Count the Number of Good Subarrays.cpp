#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int n = nums.size();
            int same = 0, right = -1;
            unordered_map<int, int> count;
            long long ans = 0;
            for (int left = 0; left < n; ++left) {
                while (same < k && right + 1 < n) {
                    ++right;
                    same += count[nums[right]];
                    ++count[nums[right]];
                }
                if (same >= k) {
                    ans += n - right;
                }
                --count[nums[left]];
                same -= count[nums[left]];
            }
            return ans;
        }
    };
