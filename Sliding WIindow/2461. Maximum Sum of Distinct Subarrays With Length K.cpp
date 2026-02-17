class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        long long cs = 0, ms = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            while (s.count(nums[r]) || s.size() == k) {
                s.erase(nums[l]);
                cs -= nums[l];
                l++;
            }
            s.insert(nums[r]);
            cs += nums[r];
            if (s.size() == k) {
                ms = max(ms, cs);
            }
        }
        return ms;
    }
};
