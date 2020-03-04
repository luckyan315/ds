#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// beats
// 8ms, 70.64%
// 14.4MB, 5.22%
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<int, int> um;
        int state = 0;
        for(int i = 0; i < cells.size(); ++i) {
            if(cells[i] > 0) state ^= 1 << i;
        }

        while (N) {
            if(um.count(state) > 0) {
                N %= um[state] - N;
            }

            um[state] = N;

            if(N >= 1) {
                N--;
                state = nextDay(state);
            }
        }

        vector<int> res(8, 0);
        for (int i = 0; i < 8; ++i) {
            if(((state >> i) & 1) > 0) res[i] = 1;
        }

        return res;
    }

    int nextDay(int state) {
        int ans = 0;
        for (int i = 1; i < 7; i++) {
            if(((state >> (i - 1)) & 1) == ((state >> (i + 1)) & 1)) {
                ans ^= 1 << i;
            }
        }

        return ans;
    }

};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> inputs = {0, 1, 0, 1, 1, 0, 0, 1};
    vector<int> res = s.prisonAfterNDays(inputs, 7);
    for(auto& e : res){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
