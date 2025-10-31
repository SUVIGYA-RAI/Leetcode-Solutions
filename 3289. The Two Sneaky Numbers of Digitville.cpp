#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> count;
        for (int x: nums) {
            count[x]++;
            if(count[x]==2) ans.push_back(x);
        }
        return ans;
    }
};