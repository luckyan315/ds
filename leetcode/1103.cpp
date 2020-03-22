#include <iostream>
#include <vector>

using namespace std;

// accept
// 4ms, beats 72.19%
// 8.7MB, beats 5.30%
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);

        int give = 1;
        while (candies) {
            for (int i = 0; i < num_people; ++i) {
                if(candies <= give) {
                    res[i] += candies;
                    return res;
                }

                res[i] += give;
                candies -= give;
                give++;
            }
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> res = s.distributeCandies(7, 4);
    for(auto& e : res){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
