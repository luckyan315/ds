#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
return s;
}
};

int main(int argc, char *argv[])
{
    Solution *pSln = new Solution();
    string str(argv[1]);
    cout<<pSln->longestPalindrome(str)<<endl;
    delete pSln;
    return 0;
}
