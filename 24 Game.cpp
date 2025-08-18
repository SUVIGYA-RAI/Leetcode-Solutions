#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int num : cards) nums.push_back(static_cast<double>(num));
        return dfs(nums);
    }

private:
    bool dfs(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<double> next;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                for (double val : generate(nums[i], nums[j])) {
                    next.push_back(val);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> generate(double a, double b) {
        vector<double> res = {a + b, a - b, b - a, a * b};
        if (fabs(b) > 1e-6) res.push_back(a / b);
        if (fabs(a) > 1e-6) res.push_back(b / a);
        return res;
    }
};