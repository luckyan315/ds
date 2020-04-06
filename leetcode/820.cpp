#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

// accept
// 500ms, 32.96%
// 14.8MB, 46.53%
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        if(words.size() == 0) return 0;
        if(words.size() == 1) return words[0].size() + 1;
        vector<string> dup(words.begin(), words.end());

        sort(dup.begin(), dup.end(), [&] (const string& a, const string& b)-> bool {
                if(a.size() > b.size()) return true;
                else if (a.size() == b.size()) {
                    return a > b;
                }
                return false;
            });

        string ss = dup[0] + "#";
        vector<int> res = {0};
        for (int i = 1; i < dup.size(); ++i) {
            size_t idx = ss.find(dup[i]);
            if(idx != string::npos && ss[idx + dup[i].length()] == '#') {
                res.push_back(idx);
            } else {
                res.push_back(ss.length());
                ss += (dup[i] + "#");
            }
        }

        // cout << ss << endl;
        // int sum = 0;
        // for(auto& e : res) {
        //     cout << e << " ";
        //     sum += e;
        // }
        // cout << endl;
        return ss.length();
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<string> input = {"ime", "time", "e", "abc"};
    cout << s.minimumLengthEncoding(input) << endl;
    return 0;
}
