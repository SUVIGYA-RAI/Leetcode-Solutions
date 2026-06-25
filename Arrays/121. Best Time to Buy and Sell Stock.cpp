#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minp=prices[0];
        int mp=0;
        for(int i=1; i<n; i++){
            if(prices[i]<minp){
                minp=prices[i];
            } else {
                int p = prices[i]-minp;
                if(p>mp) mp=p;
            }
        }
        return mp;
    }
};