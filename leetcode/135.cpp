#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// accepts
// 20ms, beats 97.01%
// 10.8MB, beats 37.63%
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> box(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) box[i] = box[i - 1] + 1;
        }

        // for (auto& e : box) cout<<e<<" ";
        // cout << endl;

        for (int i = ratings.size() - 1; i >0; i--) {
            if (ratings[i - 1] > ratings[i]) box[i - 1] = max(box[i] + 1, box[i - 1]);
        }

        int sum = 0;
        for(auto& e : box) sum += e;

        return sum;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {3,3,1,6,4,3}; // ans=10
    cout << s.candy(input) << endl;
    return 0;
}
