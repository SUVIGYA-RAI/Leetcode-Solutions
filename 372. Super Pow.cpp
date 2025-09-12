#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPow(int a,int x)
    {
        a = a%1337;

        int res = 1;

        while(x>=1)
        {
            if(x%2==1)
            {
                res = (res * a)%1337;
                x--;
            }
            else
            {
                a = (a * a)%1337;
                x/=2;
            }
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if(a==1)
        return 1;
        if(b.empty())
        return 1;
        int digit = b.back();
        b.pop_back();
        int r = calPow(a,digit);
        int m = calPow(superPow(a,b),10);
        int result = ((r%1337)*(m%1337))%1337;
        return result;
    }
};