#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        const int MOD = 1e9+7;
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        
        vector <int> dp(r+1,0);
        dp[0] = 1;
        for (int i=1; i<=n; i++) {
            for (int j = min(i,r); j>0; j--) {
                dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
        return dp[r];
    }
};