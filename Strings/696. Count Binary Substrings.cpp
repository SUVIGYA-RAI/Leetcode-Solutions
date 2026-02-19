#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int pc = 0;
        int cc = 1;
        int result = 0;

        for(int i=1; i<s.length(); i++) {
            if(s[i] == s[i-1]) cc++;
            else {
                result += min(pc,cc);
                pc = cc;
                cc = 1;
            }
        }
        result += min(pc,cc);
        return result;
    }
};