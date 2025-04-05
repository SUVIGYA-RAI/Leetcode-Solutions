#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            return dfs(nums, 0,0);
        }
    
        private:
        int dfs(vector<int>& nums, int index, int currXor) {
            if (index == nums.size()){
                return currXor;
            }
            
            int include = dfs(nums, index+1, currXor ^ nums[index]);
            int exclude = dfs(nums, index+1, currXor);
            return include + exclude;
        }
    };