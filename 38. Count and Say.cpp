#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
    public String countAndSay(int n) {
        String current = "1";
        
        for (int i = 1; i < n; i++) {
            StringBuilder nextTerm = new StringBuilder();
            int count = 1;
            
            for (int j = 1; j < current.length(); j++) {
                if (current.charAt(j) == current.charAt(j - 1)) {
                    count++;
                } else {
                    nextTerm.append(count).append(current.charAt(j - 1));
                    count = 1;
                }
            }
            nextTerm.append(count).append(current.charAt(current.length() - 1));
            current = nextTerm.toString();
        }
        
        return current;
    }
}
