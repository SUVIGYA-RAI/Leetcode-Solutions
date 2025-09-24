#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        std::string result;
        
        if ((numerator < 0) ^ (denominator < 0)) result += '-';
        
        long long n = std::llabs((long long)numerator);
        long long d = std::llabs((long long)denominator);
        
        result += std::to_string(n / d);
        
        long long remainder = n % d;
        if (remainder == 0) return result;
        
        result += '.';
        
        std::unordered_map<long long, int> remainderPos;
        
        while (remainder != 0) {
            if (remainderPos.count(remainder)) {
                result.insert(remainderPos[remainder], "(");
                result += ')';
                break;
            }
            
            remainderPos[remainder] = result.size();
            
            remainder *= 10;
            result += std::to_string(remainder / d);
            remainder %= d;
        }
        
        return result;
    }
};