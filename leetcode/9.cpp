#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        if (x >= 0 && x < 10) {
            return true;
        }

        int cnt = 0;
        int cur = x;
        while(cur) {cnt++; cur /= 10;}

        int i = 0;
        while(i <= cnt/2) {
            int last = getIndex(x, cnt - i - 1);
            cur = getIndex(x, i);
            // cout<<"index: "<<i<<" last: "<< last <<" cur: "<<cur<<endl;
            if (last != cur) {
                return false;
            }
            i++;
        }

        return true;
    }

    int getIndex(int x, int index) {
        return (x % (int)pow(10, index + 1) - x % (int) pow(10, index)) / pow(10, index);
    }
};

int main(int argc, char *argv[])
{
    Solution *pSln = new Solution();
    cout<<pSln->isPalindrome(atoi(argv[1]))<<endl;
    delete pSln;
    return 0;
}
