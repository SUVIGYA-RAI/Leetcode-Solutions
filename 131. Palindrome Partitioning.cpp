#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(int start, string &s, vector<string> &path, vector<vector<string>> &ans) {
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, path, ans);
                path.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        backtrack(0, s, path, ans);
        return ans;
    }
};
