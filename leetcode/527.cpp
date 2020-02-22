#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <queue>

using namespace std;

// accept,  136ms/38.09%,  15.1MB/100.00%
// 输入: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
// 输出: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
// l2e god internal me i6t interval inte4n f2e intr4n
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        const int LEN = dict.size();
        vector<string> ans(LEN, "");
        vector<int> prefixArray(LEN, 0);

        for (int i = 0; i < dict.size(); ++i) {
            ans[i] = getAbbrName(dict[i], 0);
        }

        for (int i = 0; i < ans.size(); i++) {
            while (true) {
                vector<int> cache;
                for (int j = i + 1; j < ans.size(); ++j) {
                    if (ans[i] == ans[j]) {
                        cache.push_back(j);
                    }
                }

                if(cache.empty()) break;

                cache.push_back(i);

                for (auto& idx : cache) {
                    ans[idx] = getAbbrName(dict[idx], ++prefixArray[idx]);
                }
            }
        }

        return ans;
    }

    string getAbbrName(string& name, int index) {
        if (name.size() - index <= 3) return name;
        return name.substr(0, index + 1) + to_string(name.size() - index - 2) + name[name.size() - 1];
    }
};

class Solution2 {
public:

    // 76ms, beats 86.76% users
    // 23.4MB, beats 100.00% users
    vector<string> wordsAbbreviation(vector<string>& dict) {
        const int LEN = dict.size();
        vector<string> ans(LEN, "");

        vector<int> arrPrefix(LEN, 0);


        for (int i = 0; i < LEN; ++i) {
            ans[i] = getAbbrName(dict[i], 0);
        }

        for (int i = 0; i < LEN; ++i) {
            while (true) {
                vector<int>  dups;

                for (int j = i + 1; j < LEN; ++j) {
                    if (i == j)  continue;

                    if (ans[i] == ans[j]) {
                        // dups.push_back(i);
                        dups.push_back(j);
                    }
                }

                if (dups.empty()) break;

                dups.push_back(i);

                for (auto& k : dups) {
                    ans[k] = getAbbrName(dict[k], ++arrPrefix[k]);
                }
            }
        }

        return ans;
    }

    string getAbbrName(string str, int index) {
        if (str.length() - index <= 3) {
            return str;
        }
        string prefix = str.substr(0, index + 1);
        return prefix + to_string(str.length() - prefix.length() - 1) + str[str.length() - 1];
    }
};


// 输入: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
// 输出: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]

// console: l2e god intern1l me i6t interv1l inte4n f2e intr4n%

int main(int argc, char *argv[])
{

    vector<string> input = {"like","god","internal","me","internet","interval","intension","face","intrusion"};

    Solution s;
    vector<string> ret;
    ret = s.wordsAbbreviation(input);

    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i];
        if (i != ret.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}
