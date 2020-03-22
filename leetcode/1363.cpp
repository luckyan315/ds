#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// accept
// 52ms, beats 16.09%
// 15.3MB, 100.00%
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<vector<int>> mp(3, vector<int>());
        int sum = 0;
        for (auto& d : digits) {
            mp[d % 3].push_back(d);
            sum += d;
        }

        sort(mp[1].begin(), mp[1].end(), greater<int>());
        sort(mp[2].begin(), mp[2].end(), greater<int>());

        int flag = sum % 3;
        string res;
        if(flag != 0) {
            if(flag == 1) {
                if(mp[1].size() > 0) {
                    mp[1].pop_back();
                } else {
                    if(mp[2].size() > 1) {
                        mp[2].pop_back();
                        mp[2].pop_back();
                    } else return "";
                }
            } else {
                if(mp[2].size() > 0) {
                    mp[2].pop_back();
                } else {
                    if(mp[1].size() > 1) {
                        mp[1].pop_back();
                        mp[1].pop_back();
                    } else return "";
                }
            }
        }

        mp[0].insert(mp[0].end(), mp[1].begin(), mp[1].end());
        mp[0].insert(mp[0].end(), mp[2].begin(), mp[2].end());

        sort(mp[0].begin(), mp[0].end(), greater<int>());

        for(int i = 0; i < mp[0].size(); ++i){
            int e = mp[0][i];
            if(i == 0 && e == 0) return "0";
            res += to_string(e);
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {8, 6, 7, 1, 0};
    cout << s.largestMultipleOfThree(input) << endl;
    return 0;
}
