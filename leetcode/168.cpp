#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// accepts
// 0ms, beats 100.00%
// 8.2MB, beats 12.64%
class Solution {
public:
    string convertToTitle(int n) {
        // cout << "n: " << n << endl;
        string s;
        while(n) {
            n -= 1;
            s += n % 26 + 'A';
            n = n / 26;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout<<s.convertToTitle(atoi(argv[1]))<<endl;
    return 0;
}
