#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        string binary = "";
        while (n > 0) {
            binary = char((n % 2) + '0') + binary;
            n /= 2;
        }

        int prev = -1;
        int maxGap = 0;
        for (int i = 0; i < binary.length(); i++) {
            if (binary[i] == '1') {
                if (prev != -1) {
                    maxGap = max(maxGap, i - prev);
                }
                prev = i;
            }
        }
        return maxGap;
    }
};