#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int, int> map;
            for (int i=0; i<n; i++) {
                map[nums[i]]++;
            }
    
            int d = nums[0];
            for (int i=1; i<n; i++) {
                if (map[nums[i]] > map[d]){
                    d = nums[i];
                }
            }
    
            vector<int> left(n);
            vector<int> right(n);
            int count = 0;
    
            for (int i=0; i<n; i++){
                if (nums[i] == d) {
                    count++;
                }
                left[i] = count;
            }
            count = 0;
            for (int i=n-1; i>=0; i--){
                if (nums[i] == d) count++;
                right[i] = count;
            }
    
            for (int i=0; i<n-1; i++){
                int s1 = i+1, s2 = n-s1;
                if (left[i] > s1/2  && right[i+1] > s2/2) {
                    return i;
                }
            }
    
            return -1;
        }
    };