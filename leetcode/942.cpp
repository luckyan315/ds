#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// accept
// 16ms, 54.41%
// 11.4MB, 5.38
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        int _min = 0;
        int _max = S.length();
        for (int i = 0; i < S.length(); ++i) {
            if(S[i] == 'I') {
                res.push_back(_min);
                _min++;
            } else if (S[i] == 'D') {
                res.push_back(_max);
                _max--;
            }

        }

        res.push_back(_min);

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str = argc == 2 ? argv[1] : "IDID";
    vector<int> res = s.diStringMatch(str);
    for (auto& e : res) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
