#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    ans = max(ans, area(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }

private:
    double area(const vector<int>& A,
                const vector<int>& B,
                const vector<int>& C) {
        long x1 = A[0], y1 = A[1];
        long x2 = B[0], y2 = B[1];
        long x3 = C[0], y3 = C[1];
        long cross = x1 * (y2 - y3)
                   + x2 * (y3 - y1)
                   + x3 * (y1 - y2);
        return 0.5 * fabs(cross);
    }
};