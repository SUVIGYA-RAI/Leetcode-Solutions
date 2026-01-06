#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthTerm(int n) {
        // code here
        int limit = max(15, (int)(n * log(n) + n * log(log(n))));
        
        vector<bool> sieve(limit + 1, true);
        sieve[0] = sieve[1] = false;

        for (int p = 2; p * p <= limit; p++) {
            if (sieve[p]) {
                for (int i = p * p; i <= limit; i += p)
                    sieve[i] = false;
            }
        }

        int count = 0;
        int nthPrime = 0;

        for (int i = 2; i <= limit; i++) {
            if (sieve[i]) {
                count++;
                if (count == n) {
                    nthPrime = i;
                    break;
                }
            }
        }

        return n * (nthPrime + 1);
    }
};
