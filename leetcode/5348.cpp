#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// accept
// 4ms, beats 100.00%
// 8.2 MB, beats 100.00%
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for (int i = 0; i < arr1.size(); ++i) {
            bool allbigger = true;
            for (int j = 0; j < arr2.size(); ++j) {
                if(abs(arr1[i] - arr2[j]) <= d) {
                    allbigger = false;
                    break;
                }
            }
            res += allbigger ? 1 : 0;
        }

        return res;
    }
};
