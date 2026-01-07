#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        
        if (n<=2) return n;
        int prev2 = 1;
        int prev1 = 2;
        int curr;
        
        for (int i=3; i<=n; i++){
            curr = prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};