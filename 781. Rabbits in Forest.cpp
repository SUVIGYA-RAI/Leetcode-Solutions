#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int, int> count;
            int result = 0;
    
            for (int a : answers) {
                count[a]++;
            }
    
            for (auto [k, v] : count) {
                int groupSize = k + 1;
                int groups = (v + groupSize - 1) / groupSize;
                result += groups * groupSize;
            }
    
            return result;
        }
    };
    