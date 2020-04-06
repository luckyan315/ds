#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int findLucky(vector<int>& arr) {
        if(arr.size() == 0) return -1;
        if(arr.size() == 1 && arr[0] == 1) return 1;
        sort(arr.begin(), arr.end());

        unordered_map<int, int> mp;
        for (int i = 0; i  < arr.size(); ++i) {
            mp[arr[i]]++;
        }

        vector<pair<int, int>> res(mp.begin(), mp.end());


        sort(res.begin(), res.end(), [&](pair<int, int>& a, pair<int, int>& b)->bool {
                if(a.second > b.second) return true;
                else if (a.second == b.second){
                    if(a.first > b.first) return true;
                }

                return false;
            });

        int m = -1;
        for (auto& e : res) {
            if(e.first == e.second) {
                m = e.second;
                break;
            }
        }

        return m;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {1, 2, 2, 3, 3, 3};
    cout << s.findLucky(input) << endl;
    return 0;
}
