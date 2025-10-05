#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j) {
        ocean[i][j] = true;
        
        for (auto dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
            
            if (x >= 0 && x < rows && y >= 0 && y < cols &&
                !ocean[x][y] && heights[x][y] >= heights[i][j]) {
                dfs(heights, ocean, x, y);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        

        for (int i = 0; i < rows; ++i)
            dfs(heights, pacific, i, 0); 
        for (int j = 0; j < cols; ++j)
            dfs(heights, pacific, 0, j); 
        

        for (int i = 0; i < rows; ++i)
            dfs(heights, atlantic, i, cols - 1); 
        for (int j = 0; j < cols; ++j)
            dfs(heights, atlantic, rows - 1, j); 

        vector<vector<int>> result;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};