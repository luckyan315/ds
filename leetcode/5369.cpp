#include <iostream>
#include <vector>

using namespace std;

// accept
// 280ms, beats 100.00%
// 7.4MB, beats 100.00%
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0;
        for (int i = 0; i < rating.size() - 2; ++i) {
            for (int j = i + 1; j < rating.size() - 1; ++j) {
                for (int k = j + 1; k < rating.size(); ++k) {
                    if((rating[i] < rating[j] && rating[j] < rating[k]) ||
                       (rating[i] > rating[j] && rating[j] > rating[k])) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main(int argc, char *argv[])
{
    vector<int> input = {2,5,3,4,1};
    Solution s;
    cout << s.numTeams(input) << endl;
    return 0;
}
