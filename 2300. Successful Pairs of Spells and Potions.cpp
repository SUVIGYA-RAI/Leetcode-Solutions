#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end());
        
        vector<int> result;
        
        
        for (int spell : spells) {
            
            long long requiredPotion = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), requiredPotion);
            result.push_back(potions.end() - it);
        }
        
        return result;
    }
};