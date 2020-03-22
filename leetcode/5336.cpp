#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    string sortString(string s) {
        if(s.length() == 0) return s;
        vector<pair<char, bool>> ori;
        for (auto& ch : s) {
            ori.push_back({ch, false});
        }

        string res;
        sort(ori.begin(), ori.end(), [&](pair<char, bool>& a, pair<char, bool>& b) -> bool {
                return a.first < b.first;
            });
        process(ori, res);
        return res;
    }

    void process(vector<pair<char, bool>>& ori, string& res) {
        char minch  = 'z' + 1;
        char maxch = 'a' - 1;
        bool flag = false;
        for (int i = 0; i < ori.size(); ++i) {
            if(ori[i].second || ori[i].first == minch) continue;
            minch = ori[i].first;
            ori[i].second = true;

            res.push_back(minch);
            flag = true;
        }

        for (int i = ori.size() - 1; i >= 0; i--) {
            if(ori[i].second || ori[i].first == maxch) continue;
            maxch = ori[i].first;
            ori[i].second = true;
            res.push_back(maxch);
            flag = true;
        }

        if(!flag) return;
        process(ori, res);
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    // cout << s.sortString("aaaabbbbcccc") << endl;
    cout << s.sortString("leetcode") << endl;
    return 0;
}
