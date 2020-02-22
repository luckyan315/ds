#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// accept
// time: 12ms, 74.79%
// memory: 8.9MB, 65.00%
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());

        int ans = 0;
        int lo = 0;
        int hi = tokens.size() - 1;
        int maxAns = 0;

        while (lo <= hi && P >= tokens[lo]) {
            P -= tokens[lo++];
            ans++;
            // cout << "ans: "<< ans << endl;
            if(maxAns < ans) maxAns = ans;

            while (ans > 0 && lo < hi && P < tokens[lo]) {
                P += tokens[hi--];
                ans--;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // vector<int> input = {100, 200, 300, 400};
    // int P = 200;

    // vector<int> input = {100, 200};
    // int P = 150;

    // vector<int> input = {100};
    // int P = 50;

    vector<int> input = {81, 91, 31};
    int P = 73;

    cout << s.bagOfTokensScore(input, P) << endl;
    return 0;
}
