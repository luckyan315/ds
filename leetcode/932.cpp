#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int N) {
        if (N == 1) return {1};
        if (N == 2) return {1, 2};

        vector<int> ret = {1, 2};

        while (ret.size() < N) {
            for (auto& e : ret) {
                e = 2 * e - 1;
            }

            for (int i = 0; i < ret.size(); ++i) {
                ret.push_back(ret[i] + 1);
            }

        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    int n = 5;
    Solution s;

    vector<int> res = s.beautifulArray(n);

    for (auto& e : res) {
        cout << e << " ";
    }

    cout << endl;

    return 0;
}
