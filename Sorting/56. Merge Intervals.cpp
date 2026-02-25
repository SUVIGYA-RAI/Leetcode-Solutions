#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        vector<bool> merged(n,false);
        for (int i=0; i<n; i++) {
            if(merged[i]) continue;
            int start = intervals[i][0];
            int end = intervals[i][1];

            for (int j=i+1; j<n; j++) {
                if(intervals[j][0] <= end) {
                    end = max(intervals[j][1], end);
                    merged[j] = true;
                } 
            }
            result.push_back({start,end});
        }
        return result;
    }
};