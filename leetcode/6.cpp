#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // P   A   H   N
    // A P L S I I G
    // Y   I   R
    // accept: 31ms
    string convert(string s, int numRows) {
        int cnt = 0; // iterate chars in s
        int iRow = 0;
        int len = s.length();
        vector<string> vs(numRows, "");
        while(iRow < numRows) {
            if (cnt == len) {
                break;
            }

            vs[iRow] += s[cnt];
            cnt++;

            if (iRow == numRows - 1) {
                // deal with obliquely
                for (int j = iRow - 1; j > 0 && cnt < len; j--, cnt++) {
                    vs[j] += s[cnt];
                }

                iRow = -1;
            }

            iRow++;
        }

        for (int i = 1; i < numRows; ++i) {
            vs[0] += vs[i];
        }
        return vs[0];
    }

    // P   A   H   N
    // A P L S I I G
    // Y   I   R
    // accept: 42ms
    string convert1(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> vs(numRows, "");
        int i = 0;
        while(i < s.length()) {
            // vertical visit
            for (int iRow = 0; iRow < numRows && i < s.length(); ++iRow, ++i) {
                vs[iRow] += s[i];
            }

            // obliquely
            for (int iRow = numRows - 2; iRow > 0 && i < s.length(); iRow--, i++) {
                vs[iRow] += s[i];
            }
        }

        for (int i = 1; i < numRows; ++i) {
            vs[0] += vs[i];
        }

        return vs[0];
    }
};

int main(int argc, char *argv[])
{
    Solution *pSln = new Solution();
    cout<<pSln->convert(string(argv[1]), atoi(argv[2]))<<endl;
    delete pSln;
    return 0;
}
