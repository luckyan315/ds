#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// accept
// 76ms, beats 21.65%
// 17.1MB, beats 38.07%
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<pair<string, bool>>> mp;
        vector<string> res;
        for (int i = 0; i < tickets.size(); i++) {
            auto& t = tickets[i];
            auto it = mp.find(t[0]);
            if(it != mp.end()) {
                it->second.push_back({t[1], false});
            } else {
                vector<pair<string, bool>> v = {{t[1], false}};
                mp[t[0]] = v;
            }
        }

        for(auto& e : mp){
            auto& dest = e.second;
            sort(dest.begin(), dest.end(), [&](pair<string, bool>& a,
                                               pair<string, bool>& b) -> bool {
                     return a.first < b.first;
                 });
        }
        int total = tickets.size() + 1;
        dfs("JFK", mp, res, total);

        return res;
    }

    bool dfs(string airport, map<string, vector<pair<string, bool>>>& mp, vector<string>& res, int total) {
        res.push_back(airport);
        if(res.size() == total) return true;
        if(mp.count(airport) == 0 && res.size() != total) return false;
        int size = mp[airport].size();
        for (int i = 0; i < size; i++) {
            if(mp[airport][i].second) continue;

            mp[airport][i].second = true;

            if(dfs(mp[airport][i].first, mp, res, total)) return true;

            res.pop_back();
            mp[airport][i].second = false;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // vector<vector<string>> input = {{"MUC", "LHR"}, {"JFK", "MUC"},
    //                                 {"SFO", "SJC"}, {"LHR", "SFO"}};

    // vector<vector<string>> input = {{"JFK", "SFO"}, {"JFK", "ATL"},
    //                                 {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};

    vector<vector<string>> input = {{"JFK", "KUL"}, {"JFK", "NRT"},
                                    {"NRT", "JFK"}};

    vector<string> res = s.findItinerary(input);
    for (auto& str : res) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
