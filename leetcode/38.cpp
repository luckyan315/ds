#include <iostream>
#include <string>

using namespace std;

// 4ms, beats 87.80%
// 8.8MB, 58.78%
class Solution {
public:
    string countAndSay(int n) {
        if(n < 1) return "";

        string ori = "1";

        while (--n) {
            int len = ori.length();
            int i = 0;
            char ch = ori[i];
            int cnt = 1;
            string res = "";
            while (i <= len - 1) {
                if(i + 1 < len && ori[i] == ori[i + 1]) {
                    cnt++;
                } else {
                    res += std::to_string(cnt);
                    res += ori[i];
                    cnt = 1;
                }
                i++;
            }

            ori = res;
        }

        return ori;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.countAndSay(5) << endl;
    return 0;
}
