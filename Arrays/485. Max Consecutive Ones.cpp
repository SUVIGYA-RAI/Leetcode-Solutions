#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int mx = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]==1) count++; 
            else count=0;
            if(count > mx) {
                mx = count;
                mx = max(count,mx);
            }
        }
        return mx;
    }
};