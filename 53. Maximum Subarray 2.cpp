#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> pre(nums.size()+1,0);
        pre[0] = 0;
        for(int i=1;i<pre.size();i++)
        {
            pre[i] = pre[i-1] + nums[i-1];
        }

        int max_sum = INT_MIN;
        int minPre = pre[0];

        for(int i=1;i<pre.size();i++)
        {
            int curr_sum = pre[i] - minPre;
            max_sum = max(max_sum,curr_sum);
            minPre = min(minPre,pre[i]);
        }
        return max_sum;
    }
};