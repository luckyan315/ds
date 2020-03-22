#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int res = 0;
        for (auto& e : nums) {
            if(e <= 5) continue;
            int k = sqrt(e);
            int cntMatch = 2;
            int sum = 1 + e;
            for (int i = 2; i <= k; ++i) {
                if(cntMatch > 4) break;
                if(e % i == 0) {
                    if(i != e / i) {
                        sum += (i + e / i);
                        cntMatch += 2;
                    } else {
                        sum += i;
                        cntMatch += 1;
                    }

                }
            }

            if(cntMatch == 4) {
                // cout << "match: " << e << endl;
                res += sum;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution s;
    cout << s.sumFourDivisors(input) << endl;
    return 0;
}
