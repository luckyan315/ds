#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> visited(266, -1);
        int start = -1;
        int substringCnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (visited[s[i]] > start) {
                start = visited[s[i]];
            }

            visited[s[i]] = i;
            substringCnt = max(substringCnt, i - start);
        }
        return substringCnt;
    }
};

int main(int argc, char *argv[]) {
    Solution *pSln = new Solution();
    string str(argv[1]);
    cout<<pSln->lengthOfLongestSubstring(str)<<endl;
    delete pSln;
    return 0;
}
