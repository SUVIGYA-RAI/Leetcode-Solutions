#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector <int> result ;
            unordered_map<char, int> index;
            int n = s.size();
    
            for (int i=0; i<n; i++) {
                index[s[i]] = i;
            }
    
            int start = 0, end = 0;
            for (int i=0; i<n; i++) {
                end = max(end, index[s[i]]);
                if (i == end) {
                    result.push_back(end-start+1);
                    start = i+1;
                }
            }
            return result;
        }
    };