#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

// accept
// 44ms, 100.00%
// 13.2MB, 100.00%
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if(votes.size() == 0) return "";
        string& res = votes[0];
        map<char, map<int, int>> f;

        for(auto& v : votes) {
            for(int i = 0; i < v.size(); ++i) {
                f[v[i]][i]++;
            }
        }


        sort(res.begin(), res.end(), [&] (char a, char b) -> bool {
                for (int i = 0; i < res.size(); i++) {
                    if(f[a][i] > f[b][i]) return true;
                    if(f[a][i] < f[b][i]) return false;
                }
                return a < b;
            });

        return res;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<string> votes = {"BCA", "CAB", "CBA", "ABC", "ACB", "BAC"};
    cout << s.rankTeams(votes) << endl;
    return 0;
}
