#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector <bool> broken(26, false);
        for (char c: brokenLetters){
            broken[c-'a'] = true;
        }

        int res = 0;

        stringstream ss(text);
        while(ss >> text){
            bool ok = true;
            for (char c: text){
                if(broken[c-'a']) {
                    ok = false;
                    break;
                }
            }
            if (ok) res++;
        }
        return res;
    }
};